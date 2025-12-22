#include "Network.h"
#include "pch.h"
#include "Process.h"
#include <cmath>
#include <string.h>

float train_prct(float* Samples, int numSamples, float* targets, float* Weights, float* bias, int Size, int numSample) {
	float total_err, err, net, out, desired, Lrn_cnst = 0.1;
	int inputDim = 2;
	int totalCycle = 0;
	bool condition = true;
	while (condition) {
		total_err = 0.0;
		for (int k = 0; k < numSample; k++) {
			net = 0.0;
			for (int i = 0; i < inputDim; i++)
				net += Weights[i] * Samples[k * inputDim + i];
			net += bias[0];
			out = sgn_net(net);
			// Backward
			if (targets[k]) desired = 1.0;
			else desired = -1.0;
			err = desired - out;
			for (int i = 0; i < inputDim; i++)
				Weights[i] += Lrn_cnst * err * Samples[k * inputDim + i];

			bias[0] += Lrn_cnst * err;
			total_err += abs(err);
		}
		totalCycle++;
		if (total_err == 0.0) condition = false;
	}
	return total_err;

} // Single Layer - Single Level

float* train_fcn(float* Samples, int numSamples, float* targets, int Dim, float* Weights, float* bias, float learning_rate, float Min_err, int Max_epoch, int& epoch, int class_count) {

	float total_err, *delta;
	float *net, *fnet, *fnet_der, *desired, *err;
	float* temp = new float[Max_epoch];
	net = new float[class_count];
	fnet = new float[class_count];
	fnet_der = new float[class_count];
	desired = new float[class_count];
	err = new float[class_count];
	delta = new float[class_count];
	epoch = 0;
	do {
		total_err = 0.0f;
		for (int step = 0; step < numSamples; step++) {
			// FeedForward
			for (int k = 0; k < class_count; k++) {
				net[k] = 0.0f;
				for (int i = 0; i < Dim; i++)
					net[k] += Weights[k * Dim + i] * Samples[step * Dim + i];

				net[k] += bias[k];
				fnet[k] = ((2.0f / (float)(1.0f + exp(-net[k]))) - 1.0f);
				fnet_der[k] = (0.5f * (1.0f - fnet[k] * fnet[k]));
			}
			// Backward
			for (int k = 0; k < class_count; k++) {
				if (targets[step] == k)
					desired[k] = 1.0;
				else desired[k] = -1.0;

				err[k] = desired[k] - fnet[k];
				delta[k] = learning_rate * err[k] * fnet_der[k];
				for (int i = 0; i < Dim; i++)
					Weights[k * Dim + i] += delta[k] * Samples[step * Dim + i];

				bias[k] += delta[k];
				total_err += (0.5f * (err[k] * err[k]));
			}
		} // for(step)

		total_err /= float(class_count * numSamples); // to find the average value
		temp[epoch] = total_err;
		epoch++;

	} while ((total_err > Min_err) && (epoch < Max_epoch));


	delete[] net;
	delete[] fnet;
	delete[] fnet_der;
	delete[] delta;
	delete[] desired;
	delete[] err;

	return temp;

}  // Single Layer - Multi Level

float* train_fcn_mlp(float* Samples, int numSamples, float* targets,
    int* layer_sizes, int num_layers_total,
    float* AllWeights, float* AllBiases,
    float learning_rate, float Min_err, int Max_epoch,
    int& epoch, int class_count)
{
    float total_err;
    float* error_history = new float[Max_epoch];

    // Check if layer_sizes matches class_count to avoid crashes
    if (layer_sizes[num_layers_total - 1] != class_count) {
        class_count = layer_sizes[num_layers_total - 1];
    }

    int input_dim = layer_sizes[0];
    float* desired = new float[class_count];
    epoch = 0;

    // Calculate Offsets
    int num_matrices = num_layers_total - 1;
    int* w_offsets = new int[num_matrices];
    int* b_offsets = new int[num_matrices];
    int* node_offsets = new int[num_layers_total];

    // track where in memory the data of the current layer will be written
    int w_ptr = 0;
    int b_ptr = 0;
    int node_ptr = 0;
    int total_nodes = 0;

    for (int i = 0; i < num_layers_total; i++) {
        node_offsets[i] = node_ptr;
        node_ptr += layer_sizes[i];
        total_nodes += layer_sizes[i];

        if (i < num_matrices) {
            w_offsets[i] = w_ptr;
            b_offsets[i] = b_ptr;
            w_ptr += (layer_sizes[i] * layer_sizes[i + 1]);
            b_ptr += layer_sizes[i + 1];
        }
    }

    // Allocate RAM for Neural Activities
    float* all_net = new float[total_nodes];
    float* all_fnet = new float[total_nodes];
    float* all_fnet_der = new float[total_nodes];
    float* all_delta = new float[total_nodes];

    // Training Loop
    do {
        total_err = 0.0f;

        for (int step = 0; step < numSamples; step++) {

            // Forward
            // Load Input Data into Layer 0
            for (int i = 0; i < input_dim; i++) {
                all_fnet[i] = Samples[step * input_dim + i];
            }

            for (int l = 0; l < num_matrices; l++) {
                int inputs = layer_sizes[l];
                int nodes = layer_sizes[l + 1];

                // Set pointers to the correct section of the arrays
                float* W = &AllWeights[w_offsets[l]];
                float* B = &AllBiases[b_offsets[l]];
                float* Input = &all_fnet[node_offsets[l]];     // Output of prev layer
                float* Net = &all_net[node_offsets[l + 1]];      // Net of curr layer
                float* Fnet = &all_fnet[node_offsets[l + 1]];    // Output of curr layer
                float* FNetDer = &all_fnet_der[node_offsets[l + 1]];

                for (int k = 0; k < nodes; k++) {
                    Net[k] = 0.0f;
                    for (int i = 0; i < inputs; i++) {
                        Net[k] += W[k * inputs + i] * Input[i];
                    }
                    Net[k] += B[k];

                    // Activation function
                    Fnet[k] = ((2.0f / (1.0f + exp(-Net[k]))) - 1.0f);
                    FNetDer[k] = (0.5f * (1.0f - Fnet[k] * Fnet[k]));
                }
            }

            // Backward

            // Output Layer Error
            int last_idx = num_layers_total - 1;
            float* OutFnet = &all_fnet[node_offsets[last_idx]];
            float* OutDer = &all_fnet_der[node_offsets[last_idx]];
            float* OutDelta = &all_delta[node_offsets[last_idx]];

            for (int k = 0; k < class_count; k++) {
                if (targets[step] == k) desired[k] = 1.0f;
                else desired[k] = -1.0f;

                float err = desired[k] - OutFnet[k];
                OutDelta[k] = learning_rate * err * OutDer[k];
                total_err += (0.5f * (err * err));
            }

            // Hidden Layers Error
            for (int l = num_matrices - 1; l > 0; l--) {
                int curr_nodes = layer_sizes[l];
                int next_nodes = layer_sizes[l + 1];

                float* W_next = &AllWeights[w_offsets[l]]; // Weights connecting this layer to next
                float* Delta_next = &all_delta[node_offsets[l + 1]];
                float* Delta_curr = &all_delta[node_offsets[l]];
                float* Der_curr = &all_fnet_der[node_offsets[l]];

                for (int j = 0; j < curr_nodes; j++) {
                    float sum = 0.0f;
                    for (int k = 0; k < next_nodes; k++) {
                        // Matrix Transpose logic
                        sum += Delta_next[k] * W_next[k * curr_nodes + j];
                    }
                    Delta_curr[j] = sum * Der_curr[j];
                }
            }

            // Update Weights
            for (int l = 0; l < num_matrices; l++) {
                int inputs = layer_sizes[l];
                int nodes = layer_sizes[l + 1];

                float* W = &AllWeights[w_offsets[l]];
                float* B = &AllBiases[b_offsets[l]];
                float* Delta = &all_delta[node_offsets[l + 1]];
                float* PrevOut = &all_fnet[node_offsets[l]];

                for (int k = 0; k < nodes; k++) {
                    for (int i = 0; i < inputs; i++) {
                        W[k * inputs + i] += Delta[k] * PrevOut[i];
                    }
                    B[k] += Delta[k];
                }
            }

        } // End Samples Loop

        total_err /= float(class_count * numSamples);
        error_history[epoch] = total_err;
        epoch++;

    } while ((total_err > Min_err) && (epoch < Max_epoch));

    // Cleanup local memory
    delete[] w_offsets; delete[] b_offsets; delete[] node_offsets;
    delete[] all_net; delete[] all_fnet; delete[] all_fnet_der; delete[] all_delta;
    delete[] desired;

    return error_history;
}


float* train_fcn_mlp_momentum(float* Samples, int numSamples, float* targets,
    int* layer_sizes, int num_layers_total,
    float* AllWeights, float* AllBiases,
    float learning_rate, float momentum, float Min_err, int Max_epoch,
    int& epoch, int class_count)
{
    float total_err;
    float* error_history = new float[Max_epoch];

    // Check if layer_sizes matches class_count to avoid crashes
    if (layer_sizes[num_layers_total - 1] != class_count) {
        class_count = layer_sizes[num_layers_total - 1];
    }

    int input_dim = layer_sizes[0];
    float* desired = new float[class_count];
    epoch = 0;

    // Calculate Offsets
    int num_matrices = num_layers_total - 1;
    int* w_offsets = new int[num_matrices];
    int* b_offsets = new int[num_matrices];
    int* node_offsets = new int[num_layers_total];

    int w_ptr = 0;
    int b_ptr = 0;
    int node_ptr = 0;
    int total_nodes = 0;

    // We need total sizes to allocate the Momentum arrays
    int total_weights_count = 0;
    int total_biases_count = 0;

    for (int i = 0; i < num_layers_total; i++) {
        node_offsets[i] = node_ptr;
        node_ptr += layer_sizes[i];
        total_nodes += layer_sizes[i];

        if (i < num_matrices) {
            w_offsets[i] = w_ptr;
            b_offsets[i] = b_ptr;

            int size_w = layer_sizes[i] * layer_sizes[i + 1];
            int size_b = layer_sizes[i + 1];

            w_ptr += size_w;
            b_ptr += size_b;

            total_weights_count += size_w;
            total_biases_count += size_b;
        }
    }

    // Allocate RAM for Neural Activities
    float* all_net = new float[total_nodes];
    float* all_fnet = new float[total_nodes];
    float* all_fnet_der = new float[total_nodes];
    float* all_delta = new float[total_nodes];

    // Momentum Arrays
    // Stores the "velocity" (previous update amount) for every weight and bias
    float* prev_W_delta = new float[total_weights_count];
    float* prev_B_delta = new float[total_biases_count];

    // Initialize Momentum arrays to 0.0
    memset(prev_W_delta, 0, total_weights_count * sizeof(float));
    memset(prev_B_delta, 0, total_biases_count * sizeof(float));

    // Training Loop
    do {
        total_err = 0.0f;

        for (int step = 0; step < numSamples; step++) {

            // Forward
            // Load Input Data into Layer 0
            for (int i = 0; i < input_dim; i++) {
                all_fnet[i] = Samples[step * input_dim + i];
            }

            for (int l = 0; l < num_matrices; l++) {
                int inputs = layer_sizes[l];
                int nodes = layer_sizes[l + 1];

                // Set pointers to the correct section of the arrays
                float* W = &AllWeights[w_offsets[l]];
                float* B = &AllBiases[b_offsets[l]];
                float* Input = &all_fnet[node_offsets[l]];     // Output of prev layer
                float* Net = &all_net[node_offsets[l + 1]];      // Net of curr layer
                float* Fnet = &all_fnet[node_offsets[l + 1]];    // Output of curr layer
                float* FNetDer = &all_fnet_der[node_offsets[l + 1]];

                for (int k = 0; k < nodes; k++) {
                    Net[k] = 0.0f;
                    for (int i = 0; i < inputs; i++) {
                        Net[k] += W[k * inputs + i] * Input[i];
                    }
                    Net[k] += B[k];

                    // Activation function
                    Fnet[k] = ((2.0f / (1.0f + exp(-Net[k]))) - 1.0f);
                    FNetDer[k] = (0.5f * (1.0f - Fnet[k] * Fnet[k]));
                }
            }

            // Backward

            // Output Layer Error
            int last_idx = num_layers_total - 1;
            float* OutFnet = &all_fnet[node_offsets[last_idx]];
            float* OutDer = &all_fnet_der[node_offsets[last_idx]];
            float* OutDelta = &all_delta[node_offsets[last_idx]];

            for (int k = 0; k < class_count; k++) {
                if (targets[step] == k) desired[k] = 1.0f;
                else desired[k] = -1.0f;

                float err = desired[k] - OutFnet[k];
                OutDelta[k] = learning_rate * err * OutDer[k];
                total_err += (0.5f * (err * err));
            }

            // Hidden Layers Error (Backprop)
            for (int l = num_matrices - 1; l > 0; l--) {
                int curr_nodes = layer_sizes[l];
                int next_nodes = layer_sizes[l + 1];

                float* W_next = &AllWeights[w_offsets[l]]; // Weights connecting this layer to next
                float* Delta_next = &all_delta[node_offsets[l + 1]];
                float* Delta_curr = &all_delta[node_offsets[l]];
                float* Der_curr = &all_fnet_der[node_offsets[l]];

                for (int j = 0; j < curr_nodes; j++) {
                    float sum = 0.0f;
                    for (int k = 0; k < next_nodes; k++) {
                        // Matrix Transpose logic: W_next[k * curr_nodes + j]
                        sum += Delta_next[k] * W_next[k * curr_nodes + j];
                    }
                    Delta_curr[j] = sum * Der_curr[j];
                }
            }

            // Update Weights - Momentum
            for (int l = 0; l < num_matrices; l++) {
                int inputs = layer_sizes[l];
                int nodes = layer_sizes[l + 1];

                float* W = &AllWeights[w_offsets[l]];
                float* B = &AllBiases[b_offsets[l]];

                // Pointers to the Momentum Arrays for this specific layer
                float* PrevW = &prev_W_delta[w_offsets[l]];
                float* PrevB = &prev_B_delta[b_offsets[l]];

                float* Delta = &all_delta[node_offsets[l + 1]];

                float* PrevOut = &all_fnet[node_offsets[l]];

                for (int k = 0; k < nodes; k++) {
                    for (int i = 0; i < inputs; i++) {

                        float current_change = Delta[k] * PrevOut[i];

                        // Apply Momentum: Change = Current + (Alpha * Previous_Change)
                        float total_change = current_change + (momentum * PrevW[k * inputs + i]);

                        W[k * inputs + i] += total_change;

                        // Store Velocity
                        PrevW[k * inputs + i] = total_change;

                    }

                    float bias_change = Delta[k] + (momentum * PrevB[k]);
                    B[k] += bias_change;
                    PrevB[k] = bias_change;
                }
            }

        } // End Samples Loop

        total_err /= float(class_count * numSamples);
        error_history[epoch] = total_err;
        epoch++;

    } while ((total_err > Min_err) && (epoch < Max_epoch));

    // Clean up
    delete[] w_offsets; delete[] b_offsets; delete[] node_offsets;
    delete[] all_net; delete[] all_fnet; delete[] all_fnet_der; delete[] all_delta;
    delete[] desired;
    delete[] prev_W_delta;
    delete[] prev_B_delta;

    return error_history;
}


float* train_regression(float* Samples, int numSamples, float* targets,
    int* layer_sizes, int num_layers_total,
    float* AllWeights, float* AllBiases,
    float learning_rate, float Min_err, int Max_epoch,
    int& epoch, int class_count)
{
    float total_err;
    float* error_history = new float[Max_epoch];

    // Check if layer_sizes matches class_count to avoid crashes
    if (layer_sizes[num_layers_total - 1] != class_count) {
        class_count = layer_sizes[num_layers_total - 1];
    }

    int input_dim = 1;
    float* desired = new float[class_count];
    epoch = 0;

    int output_dim = layer_sizes[num_layers_total - 1]; // output layer size


    // Calculate Offsets
    int num_matrices = num_layers_total - 1;
    int* w_offsets = new int[num_matrices];
    int* b_offsets = new int[num_matrices];
    int* node_offsets = new int[num_layers_total];

    int w_ptr = 0;
    int b_ptr = 0;
    int node_ptr = 0;
    int total_nodes = 0;

    for (int i = 0; i < num_layers_total; i++) {
        node_offsets[i] = node_ptr;
        node_ptr += layer_sizes[i];
        total_nodes += layer_sizes[i];

        if (i < num_matrices) {
            w_offsets[i] = w_ptr;
            b_offsets[i] = b_ptr;
            w_ptr += (layer_sizes[i] * layer_sizes[i + 1]);
            b_ptr += layer_sizes[i + 1];
        }
    }

    // Allocate RAM for Neural Activities
    float* all_net = new float[total_nodes];
    float* all_fnet = new float[total_nodes];
    float* all_fnet_der = new float[total_nodes];
    float* all_delta = new float[total_nodes];

    // Training Loop
    do {
        total_err = 0.0f;

        for (int step = 0; step < numSamples; step++) {

            // Forward
            // Load Input Data into Layer 0
            for (int i = 0; i < input_dim; i++) {
                all_fnet[i] = Samples[step * input_dim + i];
            }

            for (int l = 0; l < num_matrices; l++) {
                int inputs = layer_sizes[l];
                int nodes = layer_sizes[l + 1];

                // Set pointers to the correct section of the giant arrays
                float* W = &AllWeights[w_offsets[l]];
                float* B = &AllBiases[b_offsets[l]];
                float* Input = &all_fnet[node_offsets[l]];     // Output of prev layer
                float* Net = &all_net[node_offsets[l + 1]];      // Net of curr layer
                float* Fnet = &all_fnet[node_offsets[l + 1]];    // Output of curr layer
                float* FNetDer = &all_fnet_der[node_offsets[l + 1]];


                bool isOutputLayer = (l == num_matrices - 1);

                for (int k = 0; k < nodes; k++) {
                    Net[k] = 0.0f;
                    for (int i = 0; i < inputs; i++) {
                        Net[k] += W[k * inputs + i] * Input[i];
                    }
                    Net[k] += B[k];

                    if (isOutputLayer) {
                        // Output Layer
                        // f(x) = x, Derivative = 1
                        Fnet[k] = Net[k];
                        FNetDer[k] = 1.0f;
                    }
                    else {
                        // Hidden Layers
                        // To learn about curves, this area must remain Sigmoid.
                        float val = ((2.0f / (1.0f + exp(-Net[k]))) - 1.0f);
                        Fnet[k] = val;
                        FNetDer[k] =  (0.5f * (1.0f - Fnet[k] * Fnet[k]));
                    }
                }
            }

            // Backward

            // Output Layer Error
            int last_idx = num_layers_total - 1;
            float* OutFnet = &all_fnet[node_offsets[last_idx]];
            float* OutDer = &all_fnet_der[node_offsets[last_idx]];
            float* OutDelta = &all_delta[node_offsets[last_idx]];

            for (int k = 0; k < class_count; k++) {

                desired[k] = targets[step * output_dim + k];

                float err = desired[k] - OutFnet[k];
                OutDelta[k] = learning_rate * err * OutDer[k];
                total_err += (0.5f * (err * err));
            }

            // Hidden Layers Error
            for (int l = num_matrices - 1; l > 0; l--) {
                int curr_nodes = layer_sizes[l];
                int next_nodes = layer_sizes[l + 1];

                float* W_next = &AllWeights[w_offsets[l]]; // Weights connecting this layer to next
                float* Delta_next = &all_delta[node_offsets[l + 1]];
                float* Delta_curr = &all_delta[node_offsets[l]];
                float* Der_curr = &all_fnet_der[node_offsets[l]];

                for (int j = 0; j < curr_nodes; j++) {
                    float sum = 0.0f;
                    for (int k = 0; k < next_nodes; k++) {
                        // Matrix Transpose logic
                        sum += Delta_next[k] * W_next[k * curr_nodes + j];
                    }
                    Delta_curr[j] = sum * Der_curr[j];
                }
            }

            // Update Weights
            for (int l = 0; l < num_matrices; l++) {
                int inputs = layer_sizes[l];
                int nodes = layer_sizes[l + 1];

                float* W = &AllWeights[w_offsets[l]];
                float* B = &AllBiases[b_offsets[l]];
                float* Delta = &all_delta[node_offsets[l + 1]];
                float* PrevOut = &all_fnet[node_offsets[l]];

                for (int k = 0; k < nodes; k++) {
                    for (int i = 0; i < inputs; i++) {
                        W[k * inputs + i] += Delta[k] * PrevOut[i];
                    }
                    B[k] += Delta[k];
                }
            }

        } // End Samples Loop

        total_err /= float(class_count * numSamples);
        error_history[epoch] = total_err;
        epoch++;

    } while ((total_err > Min_err) && (epoch < Max_epoch));

    // Cleanup local memory
    delete[] w_offsets; delete[] b_offsets; delete[] node_offsets;
    delete[] all_net; delete[] all_fnet; delete[] all_fnet_der; delete[] all_delta;
    delete[] desired;

    return error_history;
}
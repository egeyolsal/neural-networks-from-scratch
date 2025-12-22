#include "pch.h"
#include <cmath>

float* Add_Data(float* sample, int Size, float* x, int Dim) {
	float* temp;
	temp = new float[Size * Dim];
	for (int i = 0; i < (Size - 1) * Dim; i++)
		temp[i] = sample[i];
	for (int i = 0; i < Dim; i++)
		temp[(Size - 1) * Dim + i] = x[i];
	//Deallocate memory
	delete[] sample;
	return temp;
}//Add_data
float* Add_Labels(float* Labels, int Size, int label) {
	float* temp;
	temp = new float[Size];
	for (int i = 0; i < Size - 1; i++)
		temp[i] = Labels[i];
	temp[Size - 1] = float(label);
	//Deallocate memory
	delete[] Labels;
	return temp;
}
float* init_array_random(int len) {
	float* arr = new float[len];
	for (int i = 0; i < len; i++)
		arr[i] = ((float)rand() / RAND_MAX) - 0.5f;
	return arr;
}
void Z_Score_Parameters(float* x, int Size, int dim, float* mean, float* std) {

	float* Total = new float[dim];

	int i, j;
	for (i = 0; i < dim; i++) {
		mean[i] = std[i] = Total[i] = 0.0;
	}
	for (i = 0; i < Size; i++)
		for (j = 0; j < dim; j++)
			Total[j] += x[i * dim + j];
	for (i = 0; i < dim; i++)
		mean[i] = Total[i] / float(Size);

	for (i = 0; i < Size; i++)
		for (j = 0; j < dim; j++)
			std[j] += ((x[i * dim + j] - mean[j]) * (x[i * dim + j] - mean[j]));

	for (j = 0; j < dim; j++)
		std[j] = sqrt(std[j] / float(Size));

	delete[] Total;

}//Z_Score_Parameters
int Test_Forward(float* x, float* weight, float* bias, int num_Class, int inputDim) {
	int i, j, index_Max;
	if (num_Class > 2) {
		float* output = new float[num_Class];
		// Calculation of the output layer input
		for (i = 0; i < num_Class; i++) {
			output[i] = 0.0f;
			for (j = 0; j < inputDim; j++)
				output[i] += weight[i * inputDim + j] * x[j];
			output[i] += bias[i];
		}
		for (i = 0; i < num_Class; i++)
			output[i] = tanh(output[i]);

		//Find Maximum in neuron
		float temp = output[0];
		index_Max = 0;
		for (i = 1; i < num_Class; i++)
			if (temp < output[i]) {
				temp = output[i];
				index_Max = i;
			}

		delete[] output;
	}
	else {
		float output = 0.0f;
		for (j = 0; j < inputDim; j++)
			output += weight[j] * x[j];
		output += bias[0];
		output = tanh(output);
		if (output > 0.0f)
			index_Max = 0;
		else index_Max = 1;
	}
	return index_Max;

}//

int sgn_net(float net) {
	if (net > 0 || net == 0) return +1;
	else return -1;
}

// Normalization
float* normalize_data(float* x, int Size, int dim) {

	float* mean = new float[dim];
	float* std = new float[dim];
	float* Total = new float[dim];
	float* temp = new float[Size * dim];
	int i, j;

	for (i = 0; i < dim; i++) {
		mean[i] = std[i] = Total[i] = 0.0;
	}
	for (i = 0; i < Size; i++)
		for (j = 0; j < dim; j++)
			Total[j] += x[i * dim + j];
	for (i = 0; i < dim; i++)
		mean[i] = Total[i] / float(Size);

	for (i = 0; i < Size; i++)
		for (j = 0; j < dim; j++)
			std[j] += ((x[i * dim + j] - mean[j]) * (x[i * dim + j] - mean[j]));

	for (j = 0; j < dim; j++)
		std[j] = sqrt(std[j] / float(Size));

	for (i = 0; i < Size; i++)
		for (j = 0; j < dim; j++)
			temp[i * dim + j] = (x[i * dim + j] - mean[j]) / std[j];

	delete[] mean;
	delete[] std;
	delete[] Total;
	return temp;

} // Z_Score

float* normalize(float* Samples, int numSample, int W, int H) {

	int dim = 2;
	float* temp = new float[dim];
	temp[0] = float(W);
	temp[1] = float(H);
	float* norm = new float[numSample * dim];
	for (int i = 0; i < numSample; i++) {
		for (int j = 0; j < dim; j++)
			norm[i * dim + j] = (Samples[i * dim + j] / temp[j]);
	}
	delete[] temp;
	return norm;
} // 0 - 1

int Test_Forward_mlp(float* inputSample, int* layer_sizes, int num_layers_total,
	float* AllWeights, float* AllBiases)
{
	// Calculate Offsets
	int num_matrices = num_layers_total - 1;
	int total_nodes = 0;
	int* node_offsets = new int[num_layers_total];
	int* w_offsets = new int[num_matrices];
	int* b_offsets = new int[num_matrices];

	int w_ptr = 0; int b_ptr = 0; int node_ptr = 0;

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

	// Allocate Temp Memory
	float* all_fnet = new float[total_nodes];

	// Load Input
	int input_dim = layer_sizes[0];
	for (int i = 0; i < input_dim; i++) all_fnet[i] = inputSample[i];

	// Forward 
	for (int l = 0; l < num_matrices; l++) {
		int inputs = layer_sizes[l];
		int nodes = layer_sizes[l + 1];

		float* W = &AllWeights[w_offsets[l]];
		float* B = &AllBiases[b_offsets[l]];
		float* Input = &all_fnet[node_offsets[l]];
		float* Output = &all_fnet[node_offsets[l + 1]];

		for (int k = 0; k < nodes; k++) {
			float net = 0.0f;
			for (int i = 0; i < inputs; i++) {
				net += W[k * inputs + i] * Input[i];
			}
			net += B[k];
			Output[k] = ((2.0f / (1.0f + exp(-net))) - 1.0f);
		}
	}

	// Find Max Class
	int last_idx = num_layers_total - 1;
	int output_dim = layer_sizes[last_idx];
	float* FinalOut = &all_fnet[node_offsets[last_idx]];

	int maxIndex = 0;
	float maxVal = FinalOut[0];
	for (int k = 1; k < output_dim; k++) {
		if (FinalOut[k] > maxVal) {
			maxVal = FinalOut[k];
			maxIndex = k;
		}
	}

	delete[] w_offsets; delete[] b_offsets; delete[] node_offsets;
	delete[] all_fnet;

	return maxIndex;
}
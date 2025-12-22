#include "Network.h"
#include "pch.h"
#include "Process.h"
#include <cmath>

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



float* train_regression(float* Samples, int numSamples, float* targets, int Dim, float* Weights, float* bias, float learning_rate, float Min_err, int Max_epoch, int& epoch, int class_count) {

	float total_err, * delta;
	float* net, * fnet, * fnet_der, * desired, * err;
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
				fnet[k] = net[k];
				fnet_der[k] = 1;
			}
			// Backward
			for (int k = 0; k < class_count; k++) {
				desired[k] = targets[step];

				err[k] = desired[k] - fnet[k];
				delta[k] = learning_rate * err[k] * fnet_der[k];
				for (int i = 0; i < Dim; i++)
					Weights[k * Dim + i] += delta[k] * Samples[step * Dim + i];

				bias[k] += delta[k];
				total_err += (0.5f * (err[k] * err[k]));
			}
		} // for(step)

		total_err /= float(class_count * numSamples);
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

} // Linear Regression
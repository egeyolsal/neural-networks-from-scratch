#pragma once

// Perception Learning Rule
float train_prct(float* Samples, int numSamples, float* targets, float* Weights, float* bias, int Size, int numSample); 

// Error Back Propagation ( Delta ) - Single Layer - Multi Level
float* train_fcn(float* Samples, int numSample, float* targets, int inputDim, float* Weights, float* bias, float learning_rate, float Min_err, int Max_epoch, int& epoch, int class_count);

// Linear Regression
float* train_regression(float* Samples, int numSamples, float* targets, int Dim, float* Weights, float* bias, float learning_rate, float Min_err, int Max_epoch, int& epoch, int class_count);
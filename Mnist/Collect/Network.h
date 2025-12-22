#pragma once

// Perception Learning Rule
float train_prct(float* Samples, int numSamples, float* targets, float* Weights, float* bias, int Size, int numSample); 

// Error Back Propagation ( Delta ) - Single Layer - Multi Level
float* train_fcn(float* Samples, int numSample, float* targets, int inputDim, float* Weights, float* bias, float learning_rate, float Min_err, int Max_epoch, int& epoch, int class_count);


float* train_fcn_mlp(float* Samples, int numSamples, float* targets,
    int* layer_sizes, int num_layers_total,
    float* AllWeights, float* AllBiases,
    float learning_rate, float Min_err, int Max_epoch,
    int& epoch, int class_count);

float* train_fcn_mlp_momentum(float* Samples, int numSamples, float* targets,
    int* layer_sizes, int num_layers_total,
    float* AllWeights, float* AllBiases,
    float learning_rate, float momentum, float Min_err, int Max_epoch,
    int& epoch, int class_count);

float* train_autoencoder(float* Samples, int numSamples,
    int* layer_sizes, int num_layers_total,
    float* AllWeights, float* AllBiases,
    float learning_rate, float Min_err, int Max_epoch,
    int& epoch);
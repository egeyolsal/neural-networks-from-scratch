# Artificial Neural Networks (ANN) - C/C++ Implementation

This project was developed for the **Artificial Neural Networks** course. The primary goal is to build a neural network engine from scratch using **C/C++** without relying on high-level libraries like PyTorch or TensorFlow.

The engine features dynamic memory management capable of processing high-dimensional data (validated on the MNIST dataset), supports both Single and Multi-Layer architectures, and includes advanced implementations such as AutoEncoders, Momentum, and Transfer Learning.

## 👨‍💻 Project Information
* **Course:** Artificial Neural Networks
* **Developer:** Ege Yolsal
* **Language:** C/C++ (Core Logic), C++/CLI (GUI - WinForms)
* **Platform:** Windows

---

## 🚀 Features & Modules

The project consists of three main core modules and several advanced deep learning techniques:

### 1. Single Layer Perceptron (SLP)
* **Classification:** Designed for linearly separable data sets using the **Delta Learning Rule**.
    * *Activation:* Bipolar Sigmoid (Tanh).
* **Regression:** Models the relationship between input and output ($y=mx+b$).
    * *Activation:* Linear function (Identity).

### 2. Multi-Layer Perceptron (MLP)
* **Dynamic Architecture:** Users can define any number of hidden layers and neurons at runtime (e.g., `2-32-16-8-5`).
* **Non-Linear Regression (Curve Fitting):** Unlike standard classifiers, the engine can model complex, non-linear continuous functions (e.g., High-degree polynomials).
    * *Hybrid Activation Architecture:* The engine implements a hybrid structure where **Hidden Layers** use **Tanh** (to capture non-linearity) and the **Output Layer** uses **Linear/Identity** activation (to allow unbounded real-value predictions beyond the [-1, 1] range).
* **Algorithm:** Generalized Delta Rule (Standard Backpropagation).
* **Memory Optimization:** Uses **Offset Mapping**. All weights and neuron values are stored in 1D dynamic arrays to prevent memory fragmentation and improve cache locality.

### 3. Advanced Techniques
* **Momentum:** Integrated to accelerate convergence and avoid local minima. Experiments showed a **~57% reduction** in training epochs.
* **AutoEncoder (AE):** Unsupervised learning model to learn compressed representations (latent space) of input data.
    * *Bottleneck Detection:* Automatically identifies the smallest layer as the bottleneck.
* **Transfer Learning:** The encoder part of a pre-trained AutoEncoder is frozen and transferred to a classifier network to solve complex tasks with higher efficiency.

---

## 🌟 Real-World Application: MNIST Digit Recognition

The true power of this custom Neural Network engine is demonstrated by its ability to scale from simple 2D coordinates to high-dimensional image processing without changing a single line of the core logic.

The system was tested using the **MNIST** dataset, which consists of $28 \times 28$ pixel grayscale images of handwritten digits (0-9).

### 🧠 Adaptation to High Dimensions
* **Seamless Integration:** The exact same `train_fcn_mlp` function developed for simple classification was used here.
* **Input Layer:** Images were flattened into **784 input neurons** ($28 \times 28$) and normalized to the [0, 1] range.
* **Architecture:** A deep architecture of `[784 -> 128 -> 64 -> 10]` was dynamically constructed at runtime.

### 🏆 Performance Statistics
Despite using a custom C++ implementation without GPU acceleration, the network achieved high convergence in just **200 epochs**.

| Metric | Result |
| :--- | :--- |
| **Final Training Error (MSE)** | `0.0019` [cite: 775] |
| **Test Set Accuracy** | **85.20%** (852/1000 Correct) |
| **Best Class Performance** | Digit **"1"** with **97.0%** accuracy |
| **Hardest Class** | Digit **"3"** with **71.0%** accuracy (due to morphological complexity) |

> **Key Insight:** This experiment proves that the engine's dynamic memory management (via pointer arithmetic) is robust enough to handle **109,184 weights** and complex matrix operations efficiently.

---

## 📊 Experimental Results

### 1. MNIST Digit Recognition
The engine was tested on the MNIST dataset ($28 \times 28$ grayscale images).
* **Architecture:** `784 -> 128 -> 64 -> 10`
* **Training Size:** 1000 Samples
* **Result:** **85.20% Accuracy** on the test set.
* **Performance:** Achieved 97.0% accuracy on digit "1".

### 2. Momentum Efficiency
Comparison on a non-linear dataset:
* **Standard Backprop:** Reached target error in **744 epochs**.
* **With Momentum (0.9):** Reached target error in **317 epochs**.

### 3. Transfer Learning (AE + MLP)
* **Pre-training:** An AutoEncoder (`784->256->64->256->784`) was trained unsupervised.
* **Fine-tuning:** The encoder weights were transferred to a classifier (`784->256->64->32->10`).
* **Result:** The hybrid model achieved **84.90% accuracy**, demonstrating successful feature extraction.

---

## 🛠 Technical Details & Mathematics

The core logic is built upon the following mathematical foundations:

**Activation Function (Tanh):**
$$f(net) = \frac{2}{1+e^{-net}} - 1$$
$$f'(net) = 0.5 \cdot (1 - f(net)^2)$$

**Weight Update with Momentum:**
To smooth out the descent and speed up training:
$$\Delta w_{ij}(t) = \eta \cdot \delta_j \cdot y_i + \alpha \cdot \Delta w_{ij}(t-1)$$
*(Where **η** is the learning rate and **α** is the momentum coefficient)*

---

## 📂 Core Functions

The project utilizes low-level pointer arithmetic and dynamic memory allocation for high performance. Here are the critical functions implementing the neural logic:

* **`train_fcn_mlp`**:
  The backbone of the project. Manages **Multi-Layer Perceptron** training with support for dynamic topology.
  * *Transfer Learning Capability:* It supports initializing the network with pre-trained weights from the AutoEncoder. This allows for **"Classifier Training with Pre-trained Encoder"**, significantly improving accuracy on complex datasets like MNIST.

* **`train_autoencoder`**:
  A specialized training loop designed for **Unsupervised Learning**. It calculates the reconstruction error ($Input \leftrightarrow Output$) instead of class labels and automatically detects the "bottleneck" layer to save the Encoder weights.

* **`train_regression`**:
  Engineered specifically for **Non-Linear Regression** tasks.
  * *Hybrid Activation:* Unlike standard classification functions, this function implements a hybrid structure using **Tanh** in hidden layers (to capture non-linear curves) and **Linear/Identity** activation in the output layer (to predict unbounded real values).

* **`train_fcn`**:
  Handles the training logic for the **Single Layer Perceptron**, supporting both basic classification and simple linear regression ($y=mx+b$).

---

## ⚙️ Installation & How to Run

This project relies on **C++/CLI** for the Windows Forms interface. It requires a Windows environment and **Visual Studio** to build.

### Prerequisites
* **Visual Studio 2022**.
* **Workload:** "Desktop development with C++".
* **Crucial Component:** You must install **"C++/CLI support for v143 build tools"** (or v142) via the Visual Studio Installer > Individual Components tab.

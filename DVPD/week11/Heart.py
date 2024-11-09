import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

heart_data = pd.read_csv('heart.csv')

# Task 1: Find the number of different items or tuples per class
print("Number of different tuples per 'output' class:")
print(heart_data['output'].value_counts())

# Task 2: Scatter plot to visualize correlations between variables
sns.pairplot(heart_data, hue='output')
plt.show()

# Task 3: Dimensionality Reduction to 2D using PCA (Without using built-in functions)
# We will manually calculate the covariance matrix, eigenvalues, and eigenvectors

# Standardize the data
heart_features = heart_data.drop(columns=['output'])  # Remove the target column
heart_mean = heart_features.mean(axis=0)
heart_standardized = heart_features - heart_mean

# Step 3.1: Manually compute the Covariance Matrix
def compute_covariance_matrix(X):
    n_samples = X.shape[0]
    covariance_matrix = (1 / (n_samples - 1)) * X.T.dot(X)
    return covariance_matrix

cov_matrix = compute_covariance_matrix(heart_standardized)
print("Covariance Matrix:\n", cov_matrix)

# Step 3.2: Manually compute eigenvalues and eigenvectors using the power iteration method
def power_iteration(A, num_simulations=100):
    # Initially, a random vector is selected
    b_k = np.random.rand(A.shape[1])
    
    for _ in range(num_simulations):
        # Calculate the matrix-by-vector product A * b_k
        b_k1 = np.dot(A, b_k)
        
        # Re-normalize the vector
        b_k1_norm = np.linalg.norm(b_k1)
        b_k = b_k1 / b_k1_norm

    return b_k

def compute_eigen(A, tolerance=1e-10):
    # Initialize an identity matrix for eigenvectors
    eigenvectors = np.zeros(A.shape)
    eigenvalues = []

    # Iteratively find the largest eigenvalue and corresponding eigenvector
    for i in range(A.shape[1]):
        # Use power iteration to find an eigenvector
        eigenvector = power_iteration(A)

        # Find the corresponding eigenvalue
        eigenvalue = np.dot(eigenvector.T, np.dot(A, eigenvector))
        eigenvalues.append(eigenvalue)
        
        # Deflate the matrix
        A = A - eigenvalue * np.outer(eigenvector, eigenvector)

        # Store the eigenvector
        eigenvectors[:, i] = eigenvector

    return np.array(eigenvalues), eigenvectors

eigenvalues, eigenvectors = compute_eigen(cov_matrix)
print("Eigenvalues:\n", eigenvalues)
print("Eigenvectors:\n", eigenvectors)

# Step 3.3: Variance explained by components
variance_explained = [(i / sum(eigenvalues)) * 100 for i in sorted(eigenvalues, reverse=True)]
print("Variance Explained by each component:\n", variance_explained)

# Step 3.4: Project the data onto the 2 principal components
projected_data = np.dot(heart_standardized, eigenvectors[:, :2])

# Task 4: Plot the input points and the corresponding computed principal components
plt.figure(figsize=(8, 6))
plt.scatter(projected_data[:, 0], projected_data[:, 1], c=heart_data['output'], cmap='coolwarm', edgecolors='k')
plt.title('PCA of Heart Data (2D)')
plt.xlabel('Principal Component 1')
plt.ylabel('Principal Component 2')
plt.grid(True)
plt.show()

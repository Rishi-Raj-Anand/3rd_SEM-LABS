# Import necessary libraries for data handling and plotting
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

# Load the Bollywood dataset with the correct encoding
bollywood_data = pd.read_csv('Movie_List.csv', encoding='ISO-8859-1')

# Task 1: Number of different items per 'Genre'
print("Number of different movies per Genre:")
print(bollywood_data['Genre'].value_counts())

# Task 2: Scatter plot for Bollywood data (Year and Genre)
plt.figure(figsize=(10, 6))
sns.countplot(data=bollywood_data, x='Year', hue='Genre')
plt.xticks(rotation=90)
plt.title('Bollywood Movies by Genre (2000-2019)')
plt.show()

# Task 3: Dimensionality Reduction to 2D using PCA (Without using built-in functions)
# We will manually calculate the covariance matrix, eigenvalues, and eigenvectors

# Standardize the data
bollywood_features = bollywood_data[['Movie_ID', 'Year']]  # Select only numeric columns
bollywood_mean = bollywood_features.mean(axis=0)
bollywood_standardized = bollywood_features - bollywood_mean

# Step 3.1: Manually compute the Covariance Matrix
def compute_covariance_matrix(X):
    n_samples = X.shape[0]
    covariance_matrix = (1 / (n_samples - 1)) * X.T.dot(X)
    return covariance_matrix

cov_matrix_bollywood = compute_covariance_matrix(bollywood_standardized)
print("Covariance Matrix for Bollywood Data:\n", cov_matrix_bollywood)

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

eigenvalues_bollywood, eigenvectors_bollywood = compute_eigen(cov_matrix_bollywood)
print("Eigenvalues for Bollywood Data:\n", eigenvalues_bollywood)
print("Eigenvectors for Bollywood Data:\n", eigenvectors_bollywood)

# Step 3.3: Project the data onto the 2 principal components
projected_data_bollywood = np.dot(bollywood_standardized, eigenvectors_bollywood[:, :2])

# Task 4: Plot the input points and the corresponding computed principal components
plt.figure(figsize=(8, 6))
plt.scatter(projected_data_bollywood[:, 0], projected_data_bollywood[:, 1], c=bollywood_data['Year'], cmap='coolwarm', edgecolors='k')
plt.title('PCA of Bollywood Data (2D)')
plt.xlabel('Principal Component 1')
plt.ylabel('Principal Component 2')
plt.grid(True)
plt.show()

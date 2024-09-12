import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# Load the cleaned data
df = pd.read_csv('cleaned_student_marks.csv')

# Function to perform binning
def binning(column, bins, method):
    """ Apply binning on a column using specified method """
    bin_edges = np.linspace(min(column), max(column), bins + 1)
    bin_indices = np.digitize(column, bin_edges, right=True)
    
    binned_values = []
    for i in range(1, bins + 1):
        bin_data = column[bin_indices == i]
        if method == 'mean':
            binned_values.extend([bin_data.mean()] * len(bin_data))
        elif method == 'median':
            binned_values.extend([bin_data.median()] * len(bin_data))
        elif method == 'boundaries':
            binned_values.extend([min(bin_data) if x - bin_edges[i - 1] < bin_edges[i] - x else max(bin_data) for x in bin_data])
    
    return binned_values

# Define the number of bins
bins = 5

# Apply binning methods on 'Mid_Sem_Marks'
df['Mid_Sem_Marks_Bin_Mean'] = binning(df['Mid_Sem_Marks'], bins, 'mean')
df['Mid_Sem_Marks_Bin_Median'] = binning(df['Mid_Sem_Marks'], bins, 'median')
df['Mid_Sem_Marks_Bin_Boundaries'] = binning(df['Mid_Sem_Marks'], bins, 'boundaries')

# Plotting histograms for the original and smoothed data

# Original Data Histogram
plt.figure(figsize=(14, 10))

plt.subplot(2, 2, 1)
plt.hist(df['Mid_Sem_Marks'], bins=bins, color='blue', edgecolor='black')
plt.title('Original Mid Sem Marks')

# Bin Mean Histogram
plt.subplot(2, 2, 2)
plt.hist(df['Mid_Sem_Marks_Bin_Mean'], bins=bins, color='green', edgecolor='black')
plt.title('Binned Mid Sem Marks (Mean)')

# Bin Median Histogram
plt.subplot(2, 2, 3)
plt.hist(df['Mid_Sem_Marks_Bin_Median'], bins=bins, color='orange', edgecolor='black')
plt.title('Binned Mid Sem Marks (Median)')

# Bin Boundaries Histogram
plt.subplot(2, 2, 4)
plt.hist(df['Mid_Sem_Marks_Bin_Boundaries'], bins=bins, color='red', edgecolor='black')
plt.title('Binned Mid Sem Marks (Boundaries)')

plt.tight_layout()
plt.show()

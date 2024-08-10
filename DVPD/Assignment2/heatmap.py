import seaborn as sns
import matplotlib.pyplot as plt
import pandas as pd

tips_df = pd.read_csv('tips.csv')

numeric_df = tips_df.select_dtypes(include=['float64', 'int64'])
plt.figure(figsize=(8, 6))
corr_matrix = numeric_df.corr()
sns.heatmap(corr_matrix, annot=True, cmap='coolwarm', fmt=".2f")
plt.title('Correlation Heatmap for Tips Dataset')
plt.show()

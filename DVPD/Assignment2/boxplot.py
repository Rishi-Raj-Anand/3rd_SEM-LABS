import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

heart_df=pd.read_csv("Heart.csv")

# Set up the matplotlib figure
plt.figure(figsize=(10, 6))

# Create a box plot
sns.boxplot(data=heart_df, x='sex', y='chol', hue='target')

# Add labels and title
plt.title('Cholesterol Levels by Sex and Heart Disease Status')
plt.xlabel('Sex (0 = Female, 1 = Male)')
plt.ylabel('Cholesterol Level')

# Show the plot
plt.show()

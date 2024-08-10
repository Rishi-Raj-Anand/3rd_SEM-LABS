import seaborn as sns
import pandas as pd
import matplotlib.pyplot as plt

iris_data = pd.read_csv('Iris.csv')

plt.figure(figsize=(10,6))
sns.histplot(iris_data['SepalLengthCm'], bins=20, kde=True)
plt.title('Distribution of Sepal Length')
plt.xlabel('Sepal Length (cm)')
plt.show()

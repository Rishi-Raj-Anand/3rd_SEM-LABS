import seaborn as sns
import pandas as pd
import matplotlib.pyplot as plt

iris_data = pd.read_csv('Iris.csv')

plt.figure(figsize=(10,6))
sns.scatterplot(x='SepalLengthCm', y='SepalWidthCm', size='PetalLengthCm', hue='Species', data=iris_data, sizes=(20, 200), alpha=0.5)
plt.title('Sepal Length vs Sepal Width')
plt.xlabel('Sepal Length (cm)')
plt.ylabel('Sepal Width (cm)')
plt.legend()
plt.show()

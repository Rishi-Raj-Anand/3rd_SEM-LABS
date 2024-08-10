import seaborn as sns
import matplotlib.pyplot as plt
import pandas as pd

iris_data = pd.read_csv('Iris.csv')

plt.figure(figsize=(10,6))
sns.stripplot(x='Species', y='SepalLengthCm', data=iris_data, jitter=True)
plt.title('Sepal Length by Species')
plt.xlabel('Species')
plt.ylabel('Sepal Length (cm)')
plt.show()

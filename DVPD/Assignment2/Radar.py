import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

iris_data = pd.read_csv('Iris.csv')

categories = ['SepalLengthCm', 'SepalWidthCm', 'PetalLengthCm', 'PetalWidthCm']
data = iris_data.groupby('Species').mean().loc['Iris-setosa', categories].values
data = np.append(data, data[0])  # Closing the circle

angles = np.linspace(0, 2 * np.pi, len(categories), endpoint=False).tolist()
angles += angles[:1]

fig, ax = plt.subplots(figsize=(6, 6), subplot_kw=dict(polar=True))
ax.fill(angles, data, color='blue', alpha=0.25)
ax.plot(angles, data, color='blue', linewidth=2)

ax.set_yticklabels([])
ax.set_xticks(angles[:-1])
ax.set_xticklabels(categories)

plt.title('Iris-setosa Characteristics')
plt.show()

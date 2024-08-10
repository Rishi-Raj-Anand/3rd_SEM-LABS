import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
import pandas as pd
import numpy as np

tips_df = pd.read_csv('tips.csv')

gender_proportions = tips_df.groupby('sex')['tip'].sum() / tips_df['tip'].sum()

total_tiles = 100
gender_tiles = (gender_proportions * total_tiles).round().astype(int)

waffle_chart = np.zeros(total_tiles)
waffle_chart[:gender_tiles['Male']] = 1

fig = plt.figure(figsize=(6, 6))
colormap = plt.cm.coolwarm
plt.matshow(waffle_chart.reshape(10, 10), cmap=colormap)
plt.colorbar()

colors = [colormap(1. * i / 2) for i in range(2)]
labels = ['Male', 'Female']
patches = [mpatches.Patch(color=colors[i], label=labels[i]) for i in range(len(labels))]
plt.legend(handles=patches, loc='lower center', ncol=len(labels), bbox_to_anchor=(0.5, -0.1))

plt.title('Proportion of Tips by Gender')
plt.show()

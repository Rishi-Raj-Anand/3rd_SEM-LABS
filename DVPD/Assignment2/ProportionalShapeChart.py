import matplotlib.pyplot as plt
import pandas as pd

tips_df = pd.read_csv('tips.csv')

day_tips = tips_df.groupby('day')['tip'].sum().sort_values()

fig, ax = plt.subplots(figsize=(10, 6))

ax.scatter(day_tips.index, [1] * len(day_tips), s=day_tips * 200, color='skyblue')

for i, value in enumerate(day_tips):
    ax.text(day_tips.index[i], 1, f'${value:.2f}', ha='center', va='center')

ax.set_yticks([])
ax.set_title('Tip Amount by Day')
ax.set_xlabel('Day of the Week')

plt.show()

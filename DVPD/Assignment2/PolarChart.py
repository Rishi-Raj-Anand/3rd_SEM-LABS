import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

tips_df = pd.read_csv('tips.csv')

tips_df['tip_percentage'] = tips_df['tip'] / tips_df['total_bill'] * 100

day_tip_percentage = tips_df.groupby('day')['tip_percentage'].mean()

angles = np.linspace(0, 2 * np.pi, len(day_tip_percentage), endpoint=False).tolist()
values = day_tip_percentage.tolist()

angles += angles[:1]
values += values[:1]

fig, ax = plt.subplots(figsize=(8, 8), subplot_kw=dict(polar=True))
ax.fill(angles, values, color='lightgreen', alpha=0.25)
ax.plot(angles, values, color='green', linewidth=2)

ax.set_xticks(angles[:-1])
ax.set_xticklabels(day_tip_percentage.index)
ax.set_title('Average Tip Percentage by Day')

plt.show()

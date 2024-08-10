import seaborn as sns
import pandas as pd
import matplotlib.pyplot as plt
tips_data=pd.read_csv("tips.csv")
tip_percentages = tips_data.groupby('day')['tip'].sum() / tips_data['tip'].sum()

plt.figure(figsize=(8,8))
plt.pie(tip_percentages, labels=tip_percentages.index, autopct='%1.1f%%', startangle=140)
plt.title('Tip Percentage by Day')
plt.show()

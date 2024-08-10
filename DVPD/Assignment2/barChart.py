import seaborn as sns
import pandas as pd
import matplotlib.pyplot as plt

tips_data = pd.read_csv('tips.csv')

plt.figure(figsize=(10,6))
sns.barplot(x='day', y='total_bill', data=tips_data, ci=None)
plt.title('Total Bill per Day')
plt.xlabel('Day of the Week')
plt.ylabel('Total Bill')
plt.show()

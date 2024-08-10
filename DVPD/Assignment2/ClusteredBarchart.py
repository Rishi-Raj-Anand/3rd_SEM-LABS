import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

tips_data = pd.read_csv('tips.csv')

plt.figure(figsize=(10,6))
sns.barplot(x='day', y='total_bill', hue='sex', data=tips_data)
plt.title('Total Bill by Day and Gender')
plt.xlabel('Day of the Week')
plt.ylabel('Total Bill')
plt.show()

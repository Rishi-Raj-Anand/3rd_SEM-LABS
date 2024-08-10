import seaborn as sns
import pandas as pd
import matplotlib.pyplot as plt

tips_data = pd.read_csv('tips.csv')

stacked_data = tips_data.groupby(['day', 'sex'])['total_bill'].sum().unstack()

stacked_data.plot(kind='bar', stacked=True, figsize=(10, 6), color=['blue', 'pink'])
plt.title('Total Bill by Day and Gender')
plt.xlabel('Day')
plt.ylabel('Total Bill')
plt.legend(title='Gender')
plt.show()

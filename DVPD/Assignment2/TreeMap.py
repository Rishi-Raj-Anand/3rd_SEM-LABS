import squarify
import matplotlib.pyplot as plt
import pandas as pd

tips_df = pd.read_csv('tips.csv')

day_total_bill = tips_df.groupby('day')['total_bill'].sum().sort_values()

fig, ax = plt.subplots(figsize=(10, 6))
squarify.plot(sizes=day_total_bill.values, label=day_total_bill.index, alpha=.8, color=plt.cm.tab20.colors)

plt.title('Total Bill by Day')
plt.axis('off')

plt.show()

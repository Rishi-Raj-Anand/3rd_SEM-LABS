import pandas as pd
import matplotlib.pyplot as plt

tips_data = pd.read_csv('tips.csv')

male_data = tips_data[tips_data['sex'] == 'Male']['total_bill'].value_counts().sort_index()
female_data = tips_data[tips_data['sex'] == 'Female']['total_bill'].value_counts().sort_index()

fig, ax = plt.subplots(figsize=(10, 6))

ax.barh(male_data.index, male_data.values, label='Male', color='blue')
ax.barh(female_data.index, -female_data.values, label='Female', color='pink')

ax.set_xlabel('Count')
ax.set_ylabel('Total Bill')
ax.set_title('Total Bill by Gender')
ax.legend()

plt.show()

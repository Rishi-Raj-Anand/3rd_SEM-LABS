import matplotlib.pyplot as plt
import pandas as pd

tips_df = pd.read_csv('tips.csv')

party_size_tips = tips_df.groupby('size')['tip'].sum().reset_index()

party_size_tips['Cumulative'] = party_size_tips['tip'].cumsum()

fig, ax = plt.subplots(figsize=(10, 6))

ax.bar(party_size_tips['size'], party_size_tips['tip'], color='green')
ax.bar(party_size_tips['size'], -party_size_tips['tip'].cumsum().shift(1).fillna(0), color='red')

ax.set_title('Incremental Tips by Size of Party')
ax.set_xlabel('Size of Party')
ax.set_ylabel('Tips')

plt.show()

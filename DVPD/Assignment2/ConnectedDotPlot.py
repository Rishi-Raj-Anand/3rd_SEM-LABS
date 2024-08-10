import pandas as pd
import matplotlib.pyplot as plt

stock_data = pd.read_csv('stock.csv')

dates = stock_data['Date'][::10]
prices_open = stock_data['Open'][::10]
prices_close = stock_data['Close'][::10]

plt.figure(figsize=(10,6))
plt.plot(dates, prices_open, 'o-', label='Low')
plt.plot(dates, prices_close, 'o-', label='High')
plt.title('High vs Low Prices')
plt.xlabel('Date')
plt.ylabel('Price')
plt.xticks(rotation=45)
plt.legend()
plt.show()

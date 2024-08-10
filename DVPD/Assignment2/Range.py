import pandas as pd
import matplotlib.pyplot as plt

stock_data = pd.read_csv('stock.csv')

plt.figure(figsize=(10,6))
plt.fill_between(stock_data['Date'], stock_data['Low'], stock_data['High'], color='skyblue', alpha=0.4)
plt.plot(stock_data['Date'], stock_data['Low'], label='Low', color='blue')
plt.plot(stock_data['Date'], stock_data['High'], label='High', color='red')
plt.title('High and Low Prices Over Time')
plt.xlabel('Date')
plt.ylabel('Price')
plt.xticks(rotation=45)
plt.legend()
plt.show()

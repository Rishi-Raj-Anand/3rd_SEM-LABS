import pandas as pd
import matplotlib.pyplot as plt

stock_data =pd.read_csv("stock.csv")

plt.figure(figsize=(10,6))
plt.fill_between(stock_data['Date'], stock_data['Close'], color="skyblue", alpha=0.4)
plt.plot(stock_data['Date'], stock_data['Close'], color="Slateblue", alpha=0.6)
plt.title('Stock Closing Price Over Time')
plt.xlabel('Date')
plt.ylabel('Closing Price')
plt.xticks(rotation=45)
plt.show()

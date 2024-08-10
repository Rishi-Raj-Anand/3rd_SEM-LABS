import pandas as pd
import matplotlib.pyplot as plt

data =pd.read_csv("stock.csv")

plt.subplot(1,2,1)
plt.title("Opening Stock")
plt.xlabel("DATE")
plt.ylabel("STOCK")
plt.plot(data['Date'],data['Open'])

plt.subplot(1,2,2)
plt.xlabel("DATE")
plt.ylabel("STOCK")
plt.plot(data['Date'],data['Close'])
plt.title("Closing Stock")

plt.suptitle("TESLA STOCK (2010-2022)",)

plt.show()
 



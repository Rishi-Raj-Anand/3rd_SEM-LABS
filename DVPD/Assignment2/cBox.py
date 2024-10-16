import matplotlib.pyplot as plt

# Sample data
data = [24, 26, 50, 53, 57, 57, 59, 59, 61, 63, 64, 65, 69, 70, 72, 74, 81, 85, 85, 86, 87]

# Create the box plot
plt.boxplot(data)

# Add labels and title
plt.ylabel('Values')
plt.title('Box Plot of Monthly Incomes')

# Show the plot
plt.show()

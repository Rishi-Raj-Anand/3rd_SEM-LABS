# Load necessary libraries
library(ggplot2)
library(plotly)
library(dygraphs)
library(highcharter)
library(lattice)
library(gganimate)
library(rgl)
library(leaflet)
library(rayrender)
library(ggvis)
library(esquisse)



# Load datasets
cost_of_living <- read.csv("C://Users//sriku//OneDrive//Desktop//3rd_SEM-LABS//DVPD//Assignment3//Cost_of_Living_Index_by_Country_2024.csv")
cancer_risk <- read.csv("C://Users//sriku//OneDrive//Desktop//3rd_SEM-LABS//DVPD//Assignment3//Risk of Developing or Dying From Cancer.csv")
tsla_stock <- read.csv("C://Users//sriku//OneDrive//Desktop//3rd_SEM-LABS//DVPD//Assignment3//TSLA.csv")

# Check the structure of each dataset
str(cost_of_living)
str(cancer_risk)
str(tsla_stock)


# Example: Bar chart of Cost of Living Index by Country
ggplot(cost_of_living, aes(x = reorder(Country, -Cost.of.Living.Index), y = Cost.of.Living.Index)) +
  geom_bar(stat = "identity") +
  coord_flip() +
  theme_minimal() +
  labs(title = "Cost of Living Index by Country", x = "Country", y = "Cost of Living Index")


#Line chart
plot_ly(data = tsla_stock, x = ~Date, y = ~Close, type = 'scatter', mode = 'lines') %>%
  layout(title = "Tesla Stock Closing Prices Over Time",
         xaxis = list(title = "Date"),
         yaxis = list(title = "Closing Price (USD)"))

# Pie chart for Cost of Living Index by Country (Top 10)
top_10 <- head(cost_of_living[order(-cost_of_living$Cost.of.Living.Index), ], 10)

ggplot(top_10, aes(x = "", y = Cost.of.Living.Index, fill = Country)) +
  geom_bar(stat = "identity", width = 1) +
  coord_polar(theta = "y") +
  theme_minimal() +
  labs(title = "Top 10 Countries by Cost of Living Index (2024)", x = "", y = "")


# Histogram of Cost of Living Index
ggplot(cost_of_living, aes(x = Cost.of.Living.Index)) +
  geom_histogram(binwidth = 5, fill = "orange", color = "black") +
  theme_minimal() +
  labs(title = "Distribution of Cost of Living Index", x = "Cost of Living Index", y = "Frequency")


# Scatter plot of Cost of Living Index vs. Country
ggplot(cost_of_living, aes(x = reorder(Country, -Cost.of.Living.Index), y = Cost.of.Living.Index)) +
  geom_point(color = "red") +
  theme_minimal() +
  labs(title = "Cost of Living Index vs. Country", x = "Country", y = "Cost of Living Index") +
  coord_flip()

# Box plot of the Cost of Living Index by Region (if applicable)
ggplot(cost_of_living, aes(x = Country, y = Cost.of.Living.Index)) +
  geom_boxplot() +
  theme_minimal() +
  labs(title = "Boxplot of Cost of Living Index by Region", x = "Region", y = "Cost of Living Index")

# Heatmap of TSLA Stock Prices
ggplot(tsla_stock, aes(x = as.Date(Date), y = factor(format(as.Date(Date), "%Y-%m")), fill = Close)) +
  geom_tile() +
  theme_minimal() +
  labs(title = "Heatmap of TSLA Stock Prices", x = "Date", y = "Month", fill = "Closing Price")


# Example: 3D surface plot for TSLA stock prices
rgl::plot3d(tsla_stock$Open, tsla_stock$Close, tsla_stock$Volume,xlab = "Opening stock",ylab = "Closing stock",zlab = "Volume", type = 's', col = 'blue',main="Tesla Stock ")


# Bubble Plot: Cost of Living Index vs Rent Index
ggplot(cost_of_living, aes(x =Cost.of.Living.Index, y =Rent.Index, size = Groceries.Index, color = Country)) +
  geom_point(alpha = 0.6) +
  theme_minimal() +
  labs(title = "Cost of Living Index vs Rent Index", x = "Cost of Living Index", y = "Rent Index", size = "Groceries Index")

# Area plot: TSLA Stock 
ggplot(tsla_stock, aes(x =Open, y = Close)) +
  geom_area(fill = "lightblue", color = "darkblue") +
  theme_minimal() +
  labs(title = "Area Plot of TSLA Stock ", x = "Opening Price", y = "Closing Price")


#Sankey diagram

data <- read.csv("C://Users//sriku//OneDrive//Desktop//3rd_SEM-LABS//DVPD//Assignment3//Risk of Developing or Dying From Cancer.csv")

library(networkD3)
nodes <- data.frame(name = c("Male", "Female", "Lung Cancer", "Breast Cancer", "Colorectal Cancer"))

links <- data.frame(source = c(0, 0, 1, 1),
                    target = c(2, 3, 2, 4),
                    value = c(1000, 1500, 800, 1200))

sankeyNetwork(Links = links, Nodes = nodes, Source = "source", Target = "target", Value = "value", NodeID = "name", fontSize = 12, nodeWidth = 30)

# Waffle Chart
library(waffle)
parts <- c(`Lung Cancer` = 50, `Breast Cancer` = 30, `Colorectal Cancer` = 20)
waffle(parts, rows = 10, title = "Proportion of Cancer Types")

#Table
library(knitr)
kable(head(data, 10), caption = "Top 10 Countries by Cost of Living Index")


# Clustered Bar Chart: Cost of Living Index vs Rent Index by Country
ggplot(cost_of_living[1:10,], aes(x = reorder(Country, -Cost.of.Living.Index))) +
  geom_bar(aes(y = Cost.of.Living.Index, fill = "Cost of Living"), stat = "identity", position = "dodge") +
  geom_bar(aes(y = Rent.Index, fill = "Rent Index"), stat = "identity", position = "dodge") +
  theme_minimal() +
  labs(title = "Cost of Living Index vs Rent Index by Country", x = "Country", y = "Index Value", fill = "Index Type")

# Dot Plot: TSLA Stock Prices
ggplot(tsla_stock, aes(x = Date, y = Close)) +
  geom_point(color = "darkblue") +
  theme_minimal() +
  labs(title = "TSLA Closing Prices", x = "Date", y = "Closing Price")


# Polar Chart: Cost of Living Index
ggplot(cost_of_living[1:10,], aes(x = reorder(Country, Cost.of.Living.Index), y = Cost.of.Living.Index)) +
  geom_bar(stat = "identity", fill = "steelblue") +
  coord_polar() +
  theme_minimal() +
  labs(title = "Polar Chart of Cost of Living Index", x = "", y = "Cost of Living Index")

# 3D Contour using volcano data for example
plot_ly(z = ~volcano) %>%
  add_contour() %>%
  layout(scene = list(xaxis = list(title = 'X Axis'),
                      yaxis = list(title = 'Y Axis'),
                      zaxis = list(title = 'Z Axis')))


# Hidden Surfaces Plot: Example using plotly
plot_ly(z = ~volcano) %>% 
  add_surface() %>% 
  layout(scene = list(zaxis = list(title = 'Z Axis'), 
                      xaxis = list(title = 'X Axis'), 
                      yaxis = list(title = 'Y Axis')))


# Install and load necessary libraries

library(treemap)

# Tree Map: Cost of Living Index by Country
treemap(cost_of_living,
        index = "Country",
        vSize = "Cost.of.Living.Index",
        vColor = "Rent.Index",
        title = "Tree Map of Cost of Living Index by Country")

# Range Chart: High and Low prices of TSLA
ggplot(tsla_stock, aes(x = Date, ymin = Low, ymax = High)) +
  geom_linerange(color = "blue") +
  theme_minimal() +
  labs(title = "Range of TSLA Stock Prices (High-Low)", x = "Date", y = "Price")







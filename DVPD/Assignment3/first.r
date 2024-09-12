library(datasets)
head(iris)
summary(iris)
plot(iris)
install.packages("pacman")
pacman::p_load(pacman,dplyr,GGally,ggplot2,ggthemes,ggvis,
               httr,lubridate,plotly,rio,rmarkdown,shiny,
               stringr,tidyr)
p_unload(dplyr,tidyr)#unloading specific package
p_unload(all)#unloading all package
detach("packages:datasets",unload = TRUE)#For unloading base package
cat("\014")#clear terminal

?plot #Help

##############################################
#PLOT()

library(datasets)
head(iris)
plot(iris$Species,iris$Sepal.Width)
plot(iris)

###############################################

plot(iris$Petal.Length,iris$Petal.Width,
col="#cc0000", #Hex code for datalab.cc red
pch=19,       #use solid circles for points
main="Iris:Petal Length vs Petal Width",
xlab="Petal length",
ylab="Petal width")

###############################################

plot(cos,0,2*pi)   #cos fxn
plot(exp,1,5)      #exponent fxn
plot(dnorm,-3,+3)  #density of normal distribution

###############################################
plot(dnorm,-3,+3,
     col="#cc1",
     lwd=5,   #line width
     main="Standard Normal Distribution",
     xlab="Z-scores",
     ylab="Density")
detach("package:datasets",unload = TRUE)
cat("\014")
###############################################

library(datasets)

?mtcars
head(mtcars)

barplot(mtcars$cyl)  #Data does not plot correctly

cylinders<-table(mtcars$cyl)
barplot(cylinders)
plot(cylinders)   #for default and plot will choose graph automatically
##############################################
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
library(simplevis)

# Load datasets
cost_of_living <- read.csv("C://Users//sriku//OneDrive//Desktop//3rd_SEM-LABS//DVPD//Assignment3//Cost_of_Living_Index_by_Country_2024.csv")


# Check the structure of each dataset
str(cost_of_living)

# Example: Bar chart of Cost of Living Index by Country
ggplot(cost_of_living, aes(x = reorder(Country, -Cost.of.Living.Index), y = Cost.of.Living.Index)) +
  geom_bar(stat = "identity") +
  coord_flip() +
  theme_minimal() +
  labs(title = "Cost of Living Index by Country", x = "Country", y = "Cost of Living Index")

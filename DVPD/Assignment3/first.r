library(ggplot2)
ggplot(data = mtcars, aes(x = wt, y = mpg)) +
  geom_point()

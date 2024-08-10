import matplotlib.pyplot as plt
import pandas as pd
from wordcloud import WordCloud
cancer_data=pd.read_csv("Cancer.csv")

text = " ".join(review for review in cancer_data['Cancer Type'])

wordcloud = WordCloud(background_color="white").generate(text)

plt.figure(figsize=(8,8))
plt.imshow(wordcloud, interpolation='bilinear')
plt.axis("off")
plt.show()

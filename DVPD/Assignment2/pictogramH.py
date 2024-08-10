import matplotlib.pyplot as plt
from matplotlib.offsetbox import OffsetImage, AnnotationBbox

categories = ['Category A', 'Category B', 'Category C']
counts = [30, 50, 20]  
icons = ['smile.png'] * len(categories)  

fig, ax = plt.subplots(figsize=(12, 8))

x_positions = [1, 2, 3]  

for i, (category, count, icon) in enumerate(zip(categories, counts, icons)):
    for j in range(count):
        img = plt.imread(icon)
        imagebox = OffsetImage(img, zoom=0.1)
        ab = AnnotationBbox(imagebox, (x_positions[i], j), frameon=False)
        ax.add_artist(ab)
plt.grid()
ax.set_xlim(0, 4)
ax.set_ylim(0, max(counts) + 10)
ax.set_xticks(x_positions)
ax.set_xticklabels(categories)
ax.set_yticks([])  

plt.title('Pictogram Example')
plt.show()

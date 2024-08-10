import plotly.graph_objects as go
import pandas as pd


cancer_df = pd.read_csv('Cancer.csv')


labels = ["Male Development", "Female Development", "Male Dying", "Female Dying"]
cancer_types = cancer_df['Cancer Type'].tolist()


source = []
target = []
values = []


for i, cancer in enumerate(cancer_types):
    source.extend([i, i, i, i])
    target.extend([len(cancer_types), len(cancer_types) + 1, len(cancer_types) + 2, len(cancer_types) + 3])
    values.extend([cancer_df['Male Risk Development Percentage'][i],
                   cancer_df['Female Risk Development Percentage'][i],
                   cancer_df['Male Risk Dying Percentage'][i],
                   cancer_df['Female Risk Dying Percentage'][i]])


labels.extend(cancer_types)


fig = go.Figure(data=[go.Sankey(
    node=dict(pad=15, thickness=20, line=dict(color="black", width=0.5), label=labels),
    link=dict(source=source, target=target, value=values)
)])

fig.update_layout(title_text="Cancer Risk Development and Dying Percentages by Gender", font_size=10)
fig.show()

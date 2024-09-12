import pandas as pd

df = pd.read_csv('student_marks.csv')

df.drop_duplicates(subset='Student_ID', keep='first', inplace=True)

df['Mid_Sem_Marks'].fillna(df['Mid_Sem_Marks'].mean(), inplace=True)
df['End_Sem_Marks'].fillna(df['End_Sem_Marks'].mean(), inplace=True)
df['Internal_Marks'].fillna(df['Internal_Marks'].mean(), inplace=True)

df['Mid_Sem_Marks'] = df['Mid_Sem_Marks'].apply(lambda x: min(max(x, 0), 30))
df['End_Sem_Marks'] = df['End_Sem_Marks'].apply(lambda x: min(max(x, 0), 50))
df['Internal_Marks'] = df['Internal_Marks'].apply(lambda x: min(max(x, 0), 20))

if df.isnull().sum().sum() == 0:
    print("Data is clean and consistent!")
else:
    print("There are still some issues in the data.")

df.to_csv('cleaned_student_marks.csv', index=False)

print("Cleaned data saved to 'cleaned_student_marks.csv'.")

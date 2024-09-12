import pandas as pd
from sklearn.preprocessing import MinMaxScaler

# Load the CSV file
file_path = 'C:/Users/sriku/OneDrive/Desktop/3rd_SEM-LABS/DVPD/Week7/student_marks.csv'  
df = pd.read_csv(file_path)

# Preprocess the data
# 1. Handle missing values: Fill missing values in numerical columns with the mean of that column
df.fillna(df.mean(numeric_only=True), inplace=True)

# 2. Remove duplicates if any
df.drop_duplicates(inplace=True)

# 3. Ensure relevant columns are numeric
df['Mid_Sem_Marks'] = pd.to_numeric(df['Mid_Sem_Marks'], errors='coerce')
df['End_Sem_Marks'] = pd.to_numeric(df['End_Sem_Marks'], errors='coerce')
df['Internal_Marks'] = pd.to_numeric(df['Internal_Marks'], errors='coerce')

# Reapply handling missing values after type conversion
df.fillna(df.mean(numeric_only=True), inplace=True)

# Normalize the specified columns using MinMaxScaler
columns_to_normalize = ['Mid_Sem_Marks', 'End_Sem_Marks', 'Internal_Marks']
scaler = MinMaxScaler()
df[columns_to_normalize] = scaler.fit_transform(df[columns_to_normalize])

# Display the preprocessed and normalized data
print(df.head())

# Save the preprocessed and normalized data to a new CSV file
output_file_path = 'C:/Users/sriku/OneDrive/Desktop/3rd_SEM-LABS/DVPD/Week7/normalized_student_marks.csv'  
df.to_csv(output_file_path, index=False)

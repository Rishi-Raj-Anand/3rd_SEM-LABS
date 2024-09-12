# Load necessary libraries
library(readr)
library(caret)

# Load the CSV file
file_path <- "C:/Users/sriku/OneDrive/Desktop/3rd_SEM-LABS/DVPD/Week7/student_marks.csv" 
df <- read_csv(file_path)

# Inspect the structure of the data
print(str(df))

# Convert relevant columns to numeric (if they aren't already)
df$Mid_Sem_Marks <- as.numeric(df$Mid_Sem_Marks)
df$End_Sem_Marks <- as.numeric(df$End_Sem_Marks)
df$Internal_Marks <- as.numeric(df$Internal_Marks)

# Handle any conversion issues (e.g., if there were non-numeric characters)
# This will replace NAs introduced by coercion with the median of the column
df$Mid_Sem_Marks[is.na(df$Mid_Sem_Marks)] <- median(df$Mid_Sem_Marks, na.rm = TRUE)
df$End_Sem_Marks[is.na(df$End_Sem_Marks)] <- median(df$End_Sem_Marks, na.rm = TRUE)
df$Internal_Marks[is.na(df$Internal_Marks)] <- median(df$Internal_Marks, na.rm = TRUE)

# Check the data again after conversion
print(str(df))

# Now proceed with normalization
columns_to_normalize <- c('Mid_Sem_Marks', 'End_Sem_Marks', 'Internal_Marks')

# Normalize the specified columns using Min-Max Scaling
preprocess_params <- preProcess(df[, columns_to_normalize], method = "range")
df[, columns_to_normalize] <- predict(preprocess_params, df[, columns_to_normalize])

# Display the preprocessed and normalized data
print(head(df))

# Save the preprocessed and normalized data to a new CSV file
output_file_path <- "C:/Users/sriku/OneDrive/Desktop/3rd_SEM-LABS/DVPD/Week7/normalizedR_student_marks.csv"  
write_csv(df, output_file_path)


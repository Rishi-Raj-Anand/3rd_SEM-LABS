import csv
import random
import numpy as np

# Function to introduce errors in the data
def introduce_errors(value, max_value):
    if random.random() < 0.1:  # 10% chance to introduce an error
        return random.randint(max_value + 1, max_value + 10)  # Out of range values
    return value

# File name for the CSV
filename = "student_marks.csv"

# Generate random marks and write to CSV
with open(filename, 'w', newline='') as csvfile:
    fieldnames = ['Student_ID', 'Mid_Sem_Marks', 'End_Sem_Marks', 'Internal_Marks']
    writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
    
    writer.writeheader()
    
    student_ids = []
    
    for i in range(100):
        student_id = 23103100 + i
        
        # Duplicate some student records
        if random.random() < 0.05:  # 5% chance of duplicating a record
            student_id = random.choice(student_ids)
        else:
            student_ids.append(student_id)
        
        mid_sem_marks = introduce_errors(random.randint(0, 30), 30)
        end_sem_marks = introduce_errors(random.randint(0, 50), 50)
        internal_marks = introduce_errors(random.randint(0, 20), 20)
        
        # Create some missing values
        if random.random() < 0.05:  # 5% chance of missing value
            mid_sem_marks = ''
        if random.random() < 0.05:
            end_sem_marks = ''
        if random.random() < 0.05:
            internal_marks = ''
        
        writer.writerow({
            'Student_ID': student_id,
            'Mid_Sem_Marks': mid_sem_marks,
            'End_Sem_Marks': end_sem_marks,
            'Internal_Marks': internal_marks
        })

print(f"CSV file '{filename}' created with random marks and some messy data.")

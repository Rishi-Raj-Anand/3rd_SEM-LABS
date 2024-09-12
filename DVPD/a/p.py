import pandas as pd
import numpy as np

# Seed for reproducibility
np.random.seed(42)

# Helper functions to generate unclean data
def generate_name():
    names = ["John", "Jane", "Smith", "Alice", "Bob", "Eve", "Tom", "Jerry", "Anna", "Chris"]
    return np.random.choice(names)

def generate_age():
    return np.random.choice([np.random.randint(18, 70), 'N/A', 'unknown', np.nan])

def generate_email(name):
    domains = ["example.com", "mail.com", "test.org"]
    if np.random.rand() > 0.8:
        return name.lower() + "@" + np.random.choice(domains)
    else:
        return name.lower() + "@" + np.random.choice(domains)[:-1]  # Introduce typo

def generate_phone():
    formats = [
        "123-456-7890", "123 456 7890", "(123) 456-7890", "123.456.7890", "+1-123-456-7890", "1234567890"
    ]
    return np.random.choice(formats)

def generate_address():
    streets = ["Main St", "High St", "Broadway", "First Ave", "Second St", "Elm St"]
    return f"{np.random.randint(1, 1000)} {np.random.choice(streets)}"

def generate_date():
    dates = [
        "2024-01-01", "01/02/2024", "2024.03.03", "March 4, 2024", "2024/05/05", "2024-06-06", np.nan
    ]
    return np.random.choice(dates)

def generate_product_id():
    ids = [f"P00{np.random.randint(1, 50)}" for _ in range(10)]
    if np.random.rand() > 0.8:
        return np.random.choice(ids) + " "  # Introduce trailing space
    else:
        return np.random.choice(ids)

def generate_quantity():
    return np.random.choice([1, 2, 3, 'three', 'NaN', 0])

# Create the unclean dataset
data = {
    "Name": [generate_name() for _ in range(100)],
    "Age": [generate_age() for _ in range(100)],
    "Email": [generate_email(name) for name in ["John", "Jane", "Smith", "Alice", "Bob", "Eve", "Tom", "Jerry", "Anna", "Chris"]*10],
    "Phone": [generate_phone() for _ in range(100)],
    "Address": [generate_address() for _ in range(100)],
    "Purchase_Date": [generate_date() for _ in range(100)],
    "Product_ID": [generate_product_id() for _ in range(100)],
    "Quantity": [generate_quantity() for _ in range(100)],
    "Price": [np.random.choice([9.99, 19.99, 5.49, 'ten', 'N/A', np.nan]) for _ in range(100)],
    "Review_Score": [np.random.choice([1, 2, 3, 4, 5, 'five', np.nan]) for _ in range(100)]
}

# Convert to DataFrame
df_unclean = pd.DataFrame(data)

# Save to CSV
file_path = "C:/Users/sriku/OneDrive/Desktop/3rd_SEM-LABS/DVPD/a/unclean_dataset.csv"
df_unclean.to_csv(file_path, index=False)

file_path

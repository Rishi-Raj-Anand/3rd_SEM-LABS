def print_star_pattern(n):
    # Loop through each line
    for i in range(n):
        # Print spaces for alignment
        print(' ' * (n - i - 1), end='')
        # Print stars
        print('* ' * (i + 1))

# Example usage
lines = int(input("Enter the number of lines: "))
print_star_pattern(lines)
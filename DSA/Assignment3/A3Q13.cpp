#include <iostream>
using namespace std;

void calculate(int a, int b, int c, int* sum, double* average, int* product) {
    *sum = a + b + c;
    *average = double(a + b + c) / 3.0;
    *product = a * b * c;
}

int main() {
    int a, b, c;
    cout << "Enter three integers: ";
    cin >> a >> b >> c;

    int sum;
    double average;
    int product;

    calculate(a, b, c, &sum, &average, &product);

    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;
    cout << "Product: " << product << endl;

    return 0;
}
#include <iostream>
using namespace std;

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        throw "Error: Division by zero is not allowed."; 
    }
    return a / b;
}

int main() {
    try {
        double num1, num2;
        char op;

        cout << "Enter first number: ";
        cin >> num1;

        if (!cin) {
            throw "Error: Invalid input. Please enter numbers only."; 
        }

        cout << "Enter an operator (+, -, *, /): ";
        cin >> op;

        cout << "Enter second number: ";
        cin >> num2;

        if (!cin) {
            throw "Error: Invalid input. Please enter numbers only.";
        }

        double result = 0;
        switch (op) {
            case '+':
                result = add(num1, num2);
                break;
            case '-':
                result = subtract(num1, num2);
                break;
            case '*':
                result = multiply(num1, num2);
                break;
            case '/':
                result = divide(num1, num2); 
                break;
            default:
                throw "Error: Invalid operator. Please use +, -, *, or /."; 
        }

        cout << "Result: " << result << endl;
    } 
    catch (const char* msg) { 
        cout << msg << endl;
    } 
    catch (...) { 
        cout<< "An unexpected error occurred!" << endl;
    }

    cout << "Program continues running smoothly!" << endl;
    return 0;
}

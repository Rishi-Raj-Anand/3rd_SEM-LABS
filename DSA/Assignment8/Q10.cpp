#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

string postfixToInfix(const string& postfix) {
    stack<string> stack;

    for (char ch : postfix) {
        if (isalnum(ch)) { // Check if the character is an operand (alphanumeric)
            stack.push(string(1, ch)); // Push the operand as a string
        } else { // The character is an operator
            // Pop the top two elements from the stack
            string operand2 = stack.top(); stack.pop();
            string operand1 = stack.top(); stack.pop();

            // Combine them in infix format
            string expression = "(" + operand1 + " " + ch + " " + operand2 + ")";
            stack.push(expression); // Push the new expression back onto the stack
        }
    }

    // The final result will be the only element left in the stack
    return stack.top();
}

int main() {
    string postfixExpression;
    cout << "Enter a postfix expression: ";
    cin >> postfixExpression;

    string infixExpression = postfixToInfix(postfixExpression);
    cout << "Infix expression: " << infixExpression << endl;

    return 0;
}
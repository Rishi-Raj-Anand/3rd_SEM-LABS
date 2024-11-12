#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <unordered_map>

using namespace std;

// Function to determine the precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0; // For non-operators
}

// Function to convert infix expression to postfix
string infixToPostfix(const string& infix) {
    stack<char> operators;
    string postfix;

    for (char token : infix) {
        // If the token is an operand (number or variable), add it to the output
        if (isalnum(token)) {
            postfix += token;
        }
        // If the token is '(', push it to the stack
        else if (token == '(') {
            operators.push(token);
        }
        // If the token is ')', pop from stack to output until '(' is found
        else if (token == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Remove '(' from stack
        }
        // If the token is an operator
        else {
            while (!operators.empty() && precedence(operators.top()) >= precedence(token)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(token);
        }
    }

    // Pop all remaining operators from the stack
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

int main() {
    string infixExpression;
    cout << "Enter an infix expression: ";
    getline(cin, infixExpression);

    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix expression: " << postfixExpression << endl;

    return 0;
}
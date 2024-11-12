#include <iostream>
#include <stack>
#include <limits>
using namespace std;

class MinStack {
private:
    stack<int> mainStack; 
    stack<int> minStack;    

public:
    void push(int x) {
        mainStack.push(x);
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }

    void pop() {
        if (mainStack.empty()) {
            cerr << "Stack is empty, cannot pop." << endl;
            return;
        }
        int top = mainStack.top();
        mainStack.pop();
        if (top == minStack.top()) {
            minStack.pop();
        }
    }

    int top() {
        if (mainStack.empty()) {
            cerr << "Stack is empty, cannot retrieve top." << endl;
            return numeric_limits<int>::min(); 
        }
        return mainStack.top();
    }

    int getMin() {
        if (minStack.empty()) {
            cerr << "Stack is empty, cannot retrieve minimum." << endl;
            return numeric_limits<int>::min();
        }
        return minStack.top();
    }

    bool isEmpty() {
        return mainStack.empty();
    }
};

int main() {
    MinStack stack;
    stack.push(5);
    cout << "Minimum: " << stack.getMin() << endl; 
    stack.push(3);
    cout << "Minimum: " << stack.getMin() << endl;
    stack.push(7);
    cout << "Minimum: " << stack.getMin() << endl; 
    stack.pop();
    cout << "Minimum: " << stack.getMin() << endl;
    stack.pop();
    cout << "Minimum: " << stack.getMin() << endl;
    stack.pop();
    cout << "Minimum: " << stack.getMin() << endl;
    return 0;
}
#include <iostream>
#include <stack>
#include <limits>
using namespace std;

class MaxStack {
private:
    stack<int> mainStack; 
    stack<int> maxStack;    

public:
    void push(int x) {
        mainStack.push(x);
        if (maxStack.empty() || x >= maxStack.top()) {
            maxStack.push(x);
        }
    }

    void pop() {
        if (mainStack.empty()) {
            cerr << "Stack is empty, cannot pop." << endl;
            return;
        }
        int top = mainStack.top();
        mainStack.pop();
        if (top == maxStack.top()) {
            maxStack.pop();
        }
    }

    int top() {
        if (mainStack.empty()) {
            cerr << "Stack is empty, cannot retrieve top." << endl;
            return numeric_limits<int>::max(); 
        }
        return mainStack.top();
    }

    int getMax() {
        if (maxStack.empty()) {
            cerr << "Stack is empty, cannot retrieve maximum." << endl;
            return numeric_limits<int>::max();
        }
        return maxStack.top();
    }

    bool isEmpty() {
        return mainStack.empty();
    }
};

int main() {
    MaxStack stack;
    stack.push(5);
    cout << "Maximum: " << stack.getMax() << endl; 
    stack.push(3);
    cout << "Maximum: " << stack.getMax() << endl;
    stack.push(7);
    cout << "Maximum: " << stack.getMax() << endl; 
    stack.pop();
    cout << "Maximum: " << stack.getMax() << endl;
    stack.pop();
    cout << "Maximum: " << stack.getMax() << endl;
    stack.pop();
    cout << "Maximum: " << stack.getMax() << endl;
    return 0;
}
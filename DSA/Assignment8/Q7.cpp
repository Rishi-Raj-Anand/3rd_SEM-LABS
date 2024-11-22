#include <iostream>
#include <stack>
using namespace std;

void sortStack(stack<int>& inputStack) {
    stack<int> auxiliaryStack;

    while (!inputStack.empty()) {
        int temp = inputStack.top();
        inputStack.pop();

        while (!auxiliaryStack.empty() && auxiliaryStack.top() > temp) {
            inputStack.push(auxiliaryStack.top());
            auxiliaryStack.pop();
        }
        auxiliaryStack.push(temp);
    }

    while (!auxiliaryStack.empty()) {
        inputStack.push(auxiliaryStack.top());
        auxiliaryStack.pop();
    }
}

int main() {
    stack<int> myStack;

    myStack.push(34);
    myStack.push(3);
    myStack.push(31);
    myStack.push(98);
    myStack.push(92);
    myStack.push(23);

    sortStack(myStack);

    cout << "Sorted stack: ";
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }

    return 0;
}
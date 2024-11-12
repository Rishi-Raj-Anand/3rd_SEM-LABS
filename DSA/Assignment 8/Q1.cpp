#include <iostream>
using namespace std;

class Stack {
private:
    int* stack;      
    int top;         
    int capacity;    
public:
    
    Stack(int size) {
        stack = new int[size]; 
        capacity = size;
        top = -1;
    }

    ~Stack() {
        delete[] stack;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int item) {
        if (isFull()) {
            cout << "Stack is full! Cannot push " << item << endl;
            return;
        }
        stack[++top] = item; 
        cout << "Pushed " << item << " to stack." << endl;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot pop." << endl;
            return -1; 
        }
        return stack[top--]; 
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int stackSize = 5;
    Stack stack(stackSize);

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();

    stack.pop();
    stack.display();

    stack.push(40);
    stack.push(50);
    stack.push(60); 
    stack.display();

    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop(); 
    return 0;
}
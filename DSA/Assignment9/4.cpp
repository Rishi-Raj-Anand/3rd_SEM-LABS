#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " added to the queue." << endl;
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue Underflow! Cannot remove an element." << endl;
            return;
        }
        Node* temp = front;
        cout << "Element " << temp->data << " removed from the queue." << endl;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    void peek() {
        if (front == nullptr) {
            cout << "Queue is empty! No front element to display." << endl;
            return;
        }
        cout << "Front element of the queue: " << front->data << endl;
    }

    void display() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements are: ";
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~Queue() {
        while (front != nullptr) {
            dequeue();
        }
    }
};

int main() {
    Queue q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.display();
    q.peek();
    q.dequeue();
    q.display();
    q.peek();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    return 0;
}

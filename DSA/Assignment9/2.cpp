#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    // Constructor to initialize a node
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Queue class
class Queue {
private:
    Node* front; // Pointer to the front node
    Node* rear;  // Pointer to the rear node

public:
    // Constructor
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Enqueue operation
    void enqueue(int value) {
        Node* newNode = new Node(value);

        // If the queue is empty
        if (rear == nullptr) {
            front = rear = newNode;
            cout << value << " added to the queue." << endl;
            return;
        }

        // Add the new node at the rear and update the rear pointer
        rear->next = newNode;
        rear = newNode;
        cout << value << " added to the queue." << endl;
    }

    // Dequeue operation
    void dequeue() {
        // Check for underflow
        if (front == nullptr) {
            cout << "Queue Underflow! Cannot remove an element." << endl;
            return;
        }

        // Remove the front node
        Node* temp = front;
        cout << "Element " << temp->data << " removed from the queue." << endl;

        front = front->next;

        // If the queue becomes empty, update rear to nullptr
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp; // Free the memory of the removed node
    }

    // Display operation
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

    // Destructor to clean up memory
    ~Queue() {
        while (front != nullptr) {
            dequeue();
        }
    }
};

int main() {
    Queue q;

    int choice, value;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << "Exiting program." << endl;
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}

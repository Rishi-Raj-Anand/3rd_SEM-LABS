#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Queue class
class Queue {
private:
    Node* front;  // Pointer to the front node
    Node* rear;   // Pointer to the rear node
    int count;    // Counter for the number of elements

public:
    // Constructor
    Queue() {
        front = nullptr;
        rear = nullptr;
        count = 0;
    }

    // Enqueue operation
    void enqueue(int value) {
        Node* newNode = new Node(value);

        // If the queue is empty
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            // Add the new node at the rear and update the rear pointer
            rear->next = newNode;
            rear = newNode;
        }
        count++; // Increment count
        cout << value << " added to the queue." << endl;
    }

    // Dequeue operation
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue Underflow! Cannot remove an element." << endl;
            return;
        }

        Node* temp = front;
        cout << "Element " << temp->data << " removed from the queue." << endl;

        front = front->next;
        delete temp; // Free memory of the removed node
        count--;     // Decrement count

        // If the queue becomes empty, update rear to nullptr
        if (front == nullptr) {
            rear = nullptr;
        }
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

    int size() {
        return count;
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
        cout << "4. Count elements\n";
        cout << "5. Exit\n";
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
                cout << "Number of elements in the queue: " << q.size() << endl;
                break;

            case 5:
                cout << "Exiting program." << endl;
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}

#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, size;
    int* queue;

public:
    // Constructor to initialize the queue
    Queue(int maxSize) {
        size = maxSize;
        queue = new int[size];
        front = -1; // Index of the first element
        rear = -1;  // Index of the last element
    }

    // Destructor to free memory
    ~Queue() {
        delete[] queue;
    }

    // Enqueue operation
    void enqueue(int value) {
        if (rear == size - 1) {
            cout << "Queue Overflow! Cannot add " << value << endl;
            return;
        }

        if (front == -1) front = 0; // Set front if the queue is initially empty
        rear++;
        queue[rear] = value;
        cout << value << " added to the queue." << endl;
    }

    // Dequeue operation
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow! Cannot remove an element." << endl;
            return;
        }

        cout << "Element " << queue[front] << " removed from the queue." << endl;
        front++;

        // Reset front and rear when the queue becomes empty
        if (front > rear) {
            front = rear = -1;
        }
    }

    // Display operation
    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue elements are: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int maxSize;
    cout << "Enter the size of the queue: ";
    cin >> maxSize;

    Queue q(maxSize);

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

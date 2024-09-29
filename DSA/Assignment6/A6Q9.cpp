// Write a program to implement a doubly linked list with operations to add, remove, and display nodes.
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void addNode(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = tail;

        if (tail != nullptr) {
            tail->next = newNode;
        } else {
            head = newNode;
        }

        tail = newNode;
    }

    void removeNode(int data) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == data) {
                if (temp->prev != nullptr) {
                    temp->prev->next = temp->next;
                } else {
                    head = temp->next;
                }

                if (temp->next != nullptr) {
                    temp->next->prev = temp->prev;
                } else {
                    tail = temp->prev;
                }

                delete temp;
                return;
            }
            temp = temp->next;
        }
    }

    void displayNodes() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << "<->";
            temp = temp->next;
        }
        cout << "NULL"<<endl;
    }
};

int main() {
    DoublyLinkedList dll;

    dll.addNode(1);
    dll.addNode(2);
    dll.addNode(3);
    dll.addNode(4);
    dll.addNode(5);

    cout << "Doubly Linked List: ";
    dll.displayNodes();

    dll.removeNode(3);

    cout << "After removing 3: ";
    dll.displayNodes();

    return 0;
}
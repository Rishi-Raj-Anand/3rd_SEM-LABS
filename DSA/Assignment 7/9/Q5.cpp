#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the end of a circular linked list
void insertEnd(Node** head, int data) {
    Node* newNode = new Node();
    newNode->data = data;

    if (*head == nullptr) {
        *head = newNode;
        newNode->next = *head;
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Function to check if a circular linked list is sorted in ascending order
bool isSorted(Node* head) {
    if (head == nullptr) return true; // An empty list is considered sorted

    Node* current = head;
    do {
        // Check if the next node's data is smaller than the current node's data
        if (current->next != head && current->data > current->next->data) {
            return false;
        }
        current = current->next;
    } while (current != head);

    return true; // List is sorted in ascending order
}

// Function to display the circular linked list
void displayList(Node* head) {
    if (head == nullptr) return;

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Insert elements into the circular linked list
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    insertEnd(&head, 5);

    cout << "Circular Linked List: ";
    displayList(head);

    // Check if the list is sorted
    if (isSorted(head)) {
        cout << "The circular linked list is sorted in ascending order." << endl;
    } else {
        cout << "The circular linked list is not sorted in ascending order." << endl;
    }

    return 0;
}

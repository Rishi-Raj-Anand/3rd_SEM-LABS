#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Function to insert a node at the beginning of the doubly linked list
void insertAtBeginning(Node** head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = *head;
    newNode->prev = nullptr;

    if (*head != nullptr) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

// Function to insert a node at the end of the doubly linked list
void insertAtEnd(Node** head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (*head == nullptr) {
        newNode->prev = nullptr;
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to insert a node at a specific position in the doubly linked list
void insertAtPosition(Node** head, int data, int position) {
    if (position <= 0) {
        cout << "Position should be greater than 0" << endl;
        return;
    }
    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }

    Node* newNode = new Node();
    newNode->data = data;
    Node* temp = *head;

    for (int i = 1; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Position out of bounds" << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

// Function to display the doubly linked list
void displayList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Insert at beginning
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    cout << "List after inserting at the beginning: ";
    displayList(head);

    // Insert at end
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    cout << "List after inserting at the end: ";
    displayList(head);

    // Insert at specific position
    insertAtPosition(&head, 25, 3);
    cout << "List after inserting at position 3: ";
    displayList(head);

    return 0;
}

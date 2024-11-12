#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Function to insert a node at the end of the doubly linked list (for testing deletions)
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

// Function to delete the first node in the doubly linked list
void deleteFirstNode(Node** head) {
    if (*head == nullptr) return;

    Node* temp = *head;
    *head = (*head)->next;

    if (*head != nullptr) {
        (*head)->prev = nullptr;
    }
    delete temp;
}

// Function to delete the last node in the doubly linked list
void deleteLastNode(Node** head) {
    if (*head == nullptr) return;

    Node* temp = *head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = nullptr;
    } else {
        *head = nullptr;
    }
    delete temp;
}

// Function to delete a node at a specific position in the doubly linked list
void deleteAtPosition(Node** head, int position) {
    if (*head == nullptr || position <= 0) {
        cout << "Position out of bounds" << endl;
        return;
    }

    Node* temp = *head;

    for (int i = 1; i < position && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Position out of bounds" << endl;
        return;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }
    delete temp;
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

    // Insert elements to test deletions
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    cout << "Initial List: ";
    displayList(head);

    // Delete the first node
    deleteFirstNode(&head);
    cout << "List after deleting the first node: ";
    displayList(head);

    // Delete the last node
    deleteLastNode(&head);
    cout << "List after deleting the last node: ";
    displayList(head);

    // Delete a node at specific position
    deleteAtPosition(&head, 2);
    cout << "List after deleting node at position 2: ";
    displayList(head);

    return 0;
}

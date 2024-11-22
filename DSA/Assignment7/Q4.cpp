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

// Function to concatenate two circular linked lists
Node* concatenateLists(Node* head1, Node* head2) {
    if (head1 == nullptr) return head2;
    if (head2 == nullptr) return head1;

    Node* temp1 = head1;
    while (temp1->next != head1) {
        temp1 = temp1->next;
    }
    
    Node* temp2 = head2;
    while (temp2->next != head2) {
        temp2 = temp2->next;
    }

    // Link end of the first list to the start of the second list
    temp1->next = head2;
    // Link end of the second list to the start of the first list
    temp2->next = head1;

    return head1; // Return the head of the concatenated list
}

// Function to display a circular linked list
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
    Node* head1 = nullptr;
    Node* head2 = nullptr;

    // Insert elements into the first circular linked list
    insertEnd(&head1, 1);
    insertEnd(&head1, 2);
    insertEnd(&head1, 3);

    // Insert elements into the second circular linked list
    insertEnd(&head2, 4);
    insertEnd(&head2, 5);
    insertEnd(&head2, 6);

    cout << "List 1: ";
    displayList(head1);

    cout << "List 2: ";
    displayList(head2);

    // Concatenate the two lists
    Node* concatenatedHead = concatenateLists(head1, head2);

    cout << "Concatenated Circular Linked List: ";
    displayList(concatenatedHead);

    return 0;
}

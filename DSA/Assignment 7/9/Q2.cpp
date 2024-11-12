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

// Function to split a circular linked list into two halves
void splitList(Node* head, Node** head1, Node** head2) {
    if (head == nullptr) return;

    Node *slow = head, *fast = head;

    // Using the Floyd's Cycle-Finding Algorithm to find the middle
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // For odd number of nodes, move `fast` to the last node
    if (fast->next->next == head) fast = fast->next;

    // Set the head pointers for the two halves
    *head1 = head;
    *head2 = slow->next;

    // Make the first half circular
    slow->next = *head1;

    // Make the second half circular
    fast->next = *head2;
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
    Node* head = nullptr;
    Node* head1 = nullptr;
    Node* head2 = nullptr;

    // Insert elements into the circular linked list
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    insertEnd(&head, 5);

    cout << "Original Circular Linked List: ";
    displayList(head);

    // Split the list
    splitList(head, &head1, &head2);

    cout << "First Half: ";
    displayList(head1);

    cout << "Second Half: ";
    displayList(head2);

    return 0;
}

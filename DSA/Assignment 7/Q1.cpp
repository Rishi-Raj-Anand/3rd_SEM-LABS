#include <iostream>
using namespace std;

// Node structure
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

// Function to merge two circular linked lists
Node* mergeLists(Node* head1, Node* head2) {
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

    // Connect end of the first list to the head of the second
    temp1->next = head2;
    // Connect end of the second list to the head of the first
    temp2->next = head1;

    return head1; // Return merged list's head
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
    Node* head1 = nullptr;
    Node* head2 = nullptr;

    // Insert elements in first circular linked list
    insertEnd(&head1, 1);
    insertEnd(&head1, 2);
    insertEnd(&head1, 3);

    // Insert elements in second circular linked list
    insertEnd(&head2, 4);
    insertEnd(&head2, 5);
    insertEnd(&head2, 6);

    cout << "List 1: ";
    displayList(head1);

    cout << "List 2: ";
    displayList(head2);

    // Merge the two circular linked lists
    Node* mergedHead = mergeLists(head1, head2);

    cout << "Merged Circular Linked List: ";
    displayList(mergedHead);

    return 0;
}

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

// Function to find the middle element of a circular linked list
int findMiddle(Node* head) {
    if (head == nullptr) {
        cout << "The list is empty." << endl;
        return -1;
    }

    Node *slow = head, *fast = head;

    // Move `fast` by two steps and `slow` by one step
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // `slow` now points to the middle element
    return slow->data;
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

    // Insert elements into the circular linked list
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    insertEnd(&head, 5);

    cout << "Circular Linked List: ";
    displayList(head);

    // Find the middle element
    int middle = findMiddle(head);
    if (middle != -1) {
        cout << "The middle element is: " << middle << endl;
    }

    return 0;
}

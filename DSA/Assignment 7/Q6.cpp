#include <iostream>
#include <stack>
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

// Function to check if the circular linked list is a palindrome
bool isPalindrome(Node* head) {
    if (head == nullptr) return true; // An empty list is a palindrome

    stack<int> s;
    Node* temp = head;

    // Traverse the list and push all elements onto a stack
    do {
        s.push(temp->data);
        temp = temp->next;
    } while (temp != head);

    // Traverse the list again and check against the stack
    temp = head;
    do {
        if (temp->data != s.top()) {
            return false; // If mismatch, the list is not a palindrome
        }
        s.pop();
        temp = temp->next;
    } while (temp != head);

    return true; // All elements matched, the list is a palindrome
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
    insertEnd(&head, 2);
    insertEnd(&head, 1);

    cout << "Circular Linked List: ";
    displayList(head);

    // Check if the list is a palindrome
    if (isPalindrome(head)) {
        cout << "The circular linked list is a palindrome." << endl;
    } else {
        cout << "The circular linked list is not a palindrome." << endl;
    }

    return 0;
}

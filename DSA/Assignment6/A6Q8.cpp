// Write a program to find the nth node from the end of a linked list.
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};


void insert(Node** head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = nullptr;

    if (*head == nullptr) {
        *head = newNode;
    } else {
        Node* lastNode = *head;
        while (lastNode->next) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
}

Node* findNthNodeFromEnd(Node* head, int n) {
    Node* mainPtr = head;
    Node* refPtr = head;

    for (int i = 0; i < n; i++) {
        if (refPtr == nullptr) {
            return nullptr; 
        }
        refPtr = refPtr->next;
    }
    while (refPtr) {
        mainPtr = mainPtr->next;
        refPtr = refPtr->next;
    }

    return mainPtr;
}

int main() {
    Node* head = nullptr;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);

    int n = 2; 
    Node* nthNode = findNthNodeFromEnd(head, n);

    if (nthNode) {
        cout << "The " << n << "th node from the end is " << nthNode->data << endl;
    } else {
        cout << "Not enough nodes in the list" << endl;
    }

    return 0;
}

// Write a program to rotate a linked list clockwise by \( k \) nodes.
#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

void rotateClockwise(Node*& head, int k) {
    if (head == nullptr || head->next == nullptr || k == 0) {
        return; // List is empty or only has one node, or k is 0
    }

    Node* current = head;
    int length = 1;

    while (current->next != nullptr) {
        current = current->next;
        length++;
    }

    current->next = head;

    Node* newTail = head;
    for (int i = 0; i < length - k % length - 1; i++) {
        newTail = newTail->next;
    }

    Node* newHead = newTail->next;

    newTail->next = nullptr;
    head = newHead;
}

int main() {
    Node* head = new Node{1, new Node{2, new Node{3, new Node{4, new Node{5, nullptr}}}}};

    rotateClockwise(head, 2);

    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}
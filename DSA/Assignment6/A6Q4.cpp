// Write a program to remove duplicates from an unsorted linked list.
#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void removeDuplicates(Node*& head) {
    unordered_set<int> seen;
    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr) {
        if (seen.find(current->data) != seen.end()) {
            previous->next = current->next;
            delete current;
        } else {
            seen.insert(current->data);
            previous = current;
        }
        current = previous->next;
    }
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node{9, new Node{2, new Node{2, new Node{7, new Node{1, new Node{0, new Node{7, nullptr}}}}}}};

    cout << "Original list: ";
    printList(head);

    removeDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}
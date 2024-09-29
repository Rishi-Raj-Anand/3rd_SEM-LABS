// Write a program to sort a linked list that contains 0s, 1s, and 2s by changing links.
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val, Node* nxt = nullptr) : data(val), next(nxt) {}
};

void sortList(Node*& head) {
    Node* zero = new Node(0);
    Node* one = new Node(0);
    Node* two = new Node(0);

    Node* z = zero;
    Node* o = one;
    Node* t = two;

    Node* curr = head;
    Node* temp;

    while (curr != nullptr) {
        temp = curr;
        curr = curr->next;

        if (temp->data == 0) {
            z->next = temp;
            z = z->next;
        } else if (temp->data == 1) {
            o->next = temp;
            o = o->next;
        } else {
            t->next = temp;
            t = t->next;
        }
        temp->next = nullptr;
    }

    z->next = one->next;
    o->next = two->next;
    t->next = nullptr;

    head = zero->next;

    delete zero;
    delete one;
    delete two;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node{0, new Node{1, new Node{2, new Node{0, new Node{1, new Node{1, nullptr}}}}}};
    
    cout << "Original List: ";
    printList(head);

    sortList(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}
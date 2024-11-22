#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

void printInRange(Node* root, int low, int high) {
    if (root == nullptr) {
        return;
    }

    if (root->data > low) {
        printInRange(root->left, low, high);
    }

    if (root->data >= low && root->data <= high) {
        cout << root->data << " ";
    }

    if (root->data < high) {
        printInRange(root->right, low, high);
    }
}

int main() {
    Node* root = nullptr;
    
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    int low = 30;
    int high = 70;

    cout << "Elements in the BST between " << low << " and " << high << " are: ";
    printInRange(root, low, high);

    return 0;
}

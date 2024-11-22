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

Node* findMin(Node* root) {
    if (root == nullptr) {
        return nullptr;  // Tree is empty
    }

    while (root->left != nullptr) {
        root = root->left;
    }

    return root;
}

Node* findMax(Node* root) {
    if (root == nullptr) {
        return nullptr;  // Tree is empty
    }

    while (root->right != nullptr) {
        root = root->right;
    }

    return root;
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

    Node* minNode = findMin(root);
    Node* maxNode = findMax(root);

    if (minNode != nullptr) {
        cout << "Minimum value in the BST: " << minNode->data << endl;
    }

    if (maxNode != nullptr) {
        cout << "Maximum value in the BST: " << maxNode->data << endl;
    }

    return 0;
}

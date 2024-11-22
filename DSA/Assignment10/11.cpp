#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

bool isBST(Node* root, int minValue, int maxValue) {
    if (root == nullptr) {
        return true;
    }

    if (root->data < minValue || root->data > maxValue) {
        return false;
    }

    return isBST(root->left, minValue, root->data - 1) &&
           isBST(root->right, root->data + 1, maxValue);
}

int main() {
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    if (isBST(root, INT_MIN, INT_MAX)) {
        cout << "The tree is a Binary Search Tree (BST)." << endl;
    } else {
        cout << "The tree is NOT a Binary Search Tree (BST)." << endl;
    }

    return 0;
}

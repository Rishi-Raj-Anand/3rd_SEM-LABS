#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

void mirror(Node* root) {
    if (root == nullptr) {
        return;
    }

    // Swap the left and right subtrees
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively mirror the left and right subtrees
    mirror(root->left);
    mirror(root->right);
}

void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "In-order traversal before mirror: ";
    inorder(root);
    cout << endl;

    mirror(root);

    cout << "In-order traversal after mirror: ";
    inorder(root);
    cout << endl;

    return 0;
}

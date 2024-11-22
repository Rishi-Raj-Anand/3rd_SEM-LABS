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

void inOrderTraversal(Node* root, int& count, int k) {
    if (root == nullptr) {
        return;
    }

    // Recur on the left subtree
    inOrderTraversal(root->left, count, k);

    // Increment the count and check if it's the k-th smallest
    count++;
    if (count == k) {
        cout << "The " << k << "-th smallest element is: " << root->data << endl;
        return;  // Stop further traversal once k-th smallest element is found
    }

    // Recur on the right subtree
    inOrderTraversal(root->right, count, k);
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

    int k = 3;  

    int count = 0;
    inOrderTraversal(root, count, k);

    return 0;
}

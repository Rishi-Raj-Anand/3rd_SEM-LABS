#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

void countNodes(Node* root, int& leafCount, int& internalCount) {
    if (root == nullptr) {
        return;
    }

    if (root->left == nullptr && root->right == nullptr) {
        leafCount++;
    } else {
        internalCount++;
    }

    countNodes(root->left, leafCount, internalCount);
    countNodes(root->right, leafCount, internalCount);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int leafCount = 0, internalCount = 0;
    countNodes(root, leafCount, internalCount);

    cout << "Leaf nodes count: " << leafCount << endl;
    cout << "Internal nodes count: " << internalCount << endl;

    return 0;
}

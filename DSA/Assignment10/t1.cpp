#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;
   
    Node(int v):val(v),left(NULL),right(NULL){}
};

// 1. Write a C program to implement a simple tree structure and perform insertion & Deletion of nodes.
Node*BuildBinaryTreeHelper(vector<int>&pre,int &i){
    if(pre[i]==-1){
        return NULL;
    }

    Node*root=new Node(pre[i]);
    root->left=BuildBinaryTreeHelper(pre,++i);
    root->right=BuildBinaryTreeHelper(pre,++i);
    return root;
}
Node*BuildBinaryTree(vector<int>pre){
    int i=0;
    return BuildBinaryTreeHelper(pre,i);
}

// 4. Write a C program to perform a pre-order/in-order/post-order/level-order traversal of a binary tree.

void preorderTraverasal(Node*root){
    if(root==NULL){
        return;
    }
    cout<<root->val<<" ";
    preorderTraverasal(root->left);
    preorderTraverasal(root->right);
}

void inorderTraversal(Node*root){
    if(root==NULL){
        return;
    }
    inorderTraversal(root->left);
    cout<<root->val<<" ";
    inorderTraversal(root->right);
    return;
}

void postorderTraversal(Node*root){

    if(root==NULL){
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->val<<" ";
    return;
}

void levelorderTraversal(Node*root){
    if(root==NULL){
        return;
    }

    queue<Node*>Q;
    Q.push(root);
    while(!Q.empty()){
        Node*curr=Q.front();

        cout<<curr->val<<" ";

        if(curr->left!=NULL){
            Q.push(curr->left);
        }

        if(curr->right!=NULL){
            Q.push(curr->right);
        }
        Q.pop();
    }

}

// 2. Write a C program to find the height of a tree.
int Height(Node*root){
    if(root==NULL){
        return 0;
    }

    int leftH=Height(root->left);
    int rightH=Height(root->right);

    return max(leftH,rightH)+1;
}

// 3. Write a C program to implement a function that checks whether a given tree is symmetric.
    bool isSymmetricHelper(Node* left, Node* right) {
    if (left == NULL && right == NULL) {
        return true; 
    }
    if (left == NULL || right == NULL) {
        return false; 
    }
    
    return (left->val == right->val) && 
           isSymmetricHelper(left->left, right->right) && 
           isSymmetricHelper(left->right, right->left);
}

bool isSymmetric(Node* root) {
    return isSymmetricHelper(root, root);
}


// 6. Write a C program to check if two binary trees are identical.
bool isIdentical(Node*root1,Node*root2){
    if(root1==NULL && root2==NULL){
        return true;
    }else if(root1==NULL||root2==NULL){
        return false;
    }

    if(root1->val!=root2->val){
        return false;
    }
    return isIdentical(root1->left,root2->left)&&isIdentical(root1->right,root2->right);
}

// 5. Write a C program to count the total number of internal(non-leaf) and leaf Node in a binary tree.

int countLeafNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int countInternalNodes(Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return 0;
    }
    return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
}

// 7. Write a C program to implement mirror conversion of a binary tree.
    void mirror(Node* root) {
    if (root == NULL) {
        return;
    }

    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

int main(){
    vector<int>preorder1={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    vector<int>preorder2={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node*BT1=BuildBinaryTree(preorder1);
    Node*BT2=BuildBinaryTree(preorder2);
    // deleteNode(BT,3);
    // cout<<"Preorder :";
    // preorderTraverasal(BT);
    // cout<<endl;
    cout<<"Preorder :";
    preorderTraverasal(BT1);
    cout<<endl;
    cout<<"Postorder :";
    postorderTraversal(BT1);
    cout<<endl;
    cout<<"Inorder :";
    inorderTraversal(BT1);
    cout<<endl;
    cout<<"Levelorder :";
    levelorderTraversal(BT1);
    cout<<endl;

    cout<<"Height :"<<Height(BT1)<<endl;

    cout<<"is Identical :"<<isIdentical(BT1,BT2)<<endl;

    vector<int>preorder3={1,2,4,-1,-1,3,-1,-1,2,3,-1,-1,4,-1,-1};
    Node*BT3=BuildBinaryTree(preorder3);
    cout<<"isSymmetric :"<<isSymmetric(BT3)<<endl;


    int leafCount = countLeafNodes(BT1);
    int internalCount = countInternalNodes(BT2);

    cout << "Number of leaf nodes: " << leafCount << endl;
    cout << "Number of internal (non-leaf) nodes: " << internalCount << endl;

    mirror(BT1);
    cout<<"Inorder :";
    inorderTraversal(BT1);
    cout<<endl;



}


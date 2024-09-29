// Write a program to find the intersection point of two linked lists.
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node():data(0),next(NULL){}
    Node(int a,Node*x):data(a),next(x){}
    Node(int a):data(a),next(NULL){}
};
void printLL(Node*&h){
    Node*temp=h;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
        
    }
    cout<<"NULL"<<endl;
}

Node* findIntersection(Node* head1, Node* head2) {
    Node* temp1 = head1;
    Node* temp2 = head2;
    int len1 = 0, len2 = 0;
    
    while (temp1 != NULL) {
        len1++;
        temp1 = temp1->next;
    }
    
    while (temp2 != NULL) {
        len2++;
        temp2 = temp2->next;
    }
    
    temp1 = head1;
    temp2 = head2;
    
    if (len1 > len2) {
        for (int i = 0; i < len1 - len2; i++) {
            temp1 = temp1->next;
        }
    } else {
        for (int i = 0; i < len2 - len1; i++) {
            temp2 = temp2->next;
        }
    }
    
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1 == temp2) {
            return temp1;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    
    return NULL;
}

int main() {
    Node n5(5), n4(4, &n5), n3(3, &n4), n2(2, &n3), n1(1, &n2);
    Node* head1 = &n1;
    Node x3(10), x2(9, &x3), x1(8, &x2);
    Node* head2 = &x1;
    x3.next = &n3;
    
    printLL(head1);
    printLL(head2);
    
    Node* intersection = findIntersection(head1, head2);
    if (intersection != NULL) {
        cout << "Intersection point: " << intersection->data << endl;
    } else {
        cout << "No intersection point" << endl;
    }
    
    return 0;
}



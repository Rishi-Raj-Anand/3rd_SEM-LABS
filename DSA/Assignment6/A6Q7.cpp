// Write a program to check if a linked list is a palindrome.
#include<iostream>
#include<vector>
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

void ispalindrome(Node*&h){
    vector<int>v;
    Node*temp=h;
    while(temp!=NULL){
        v.push_back(temp->data);
        temp=temp->next;
    }

    int s=0,e=v.size()-1;
    while(s<e){
        if(v[s]!=v[e]){
            cout<<"Not a palindrome ";
            return;
        }
        s++;
        e--;
    }
    cout<<"Palindrome";
    return;

}

int main(){
    Node n5(1),n4(2,&n5),n3(3,&n4),n2(2,&n3),n1(1,&n2);
    Node*Head=&n1;
    printLL(Head);
    ispalindrome(Head);

    return 0;
}
// Write a program to segregate even and odd nodes in a linked list.
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

class Slist{
    public:
    Node*Head=NULL;
    Node*Tail=NULL;

    void PrintLL(){
        Node*temp=Head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }

    void push_front(int n){
        Node*newNode=new Node(n);
        if(Head==NULL){
            Head=Tail=newNode;
        }else{
            newNode->next=Head;
            Head=newNode;
        }
    }

    void push_back(int n){
        Node*newNode=new Node(n);
        if(Head==NULL){
            Head=Tail=newNode;
        }else{
            Tail->next=newNode;
            Tail=newNode;
        }
    }

    void insert(int n,int pos){
        Node* newNode=new Node(n);
        Node*prev=NULL;
        Node*Next=Head;
        for(int i=0;i<pos;i++){
            prev=Next;
            Next=Next->next;
        }
        prev->next=newNode;
        newNode->next=Next;
    }

    void pop_front(){
        Node*temp=Head;
        Head=Head->next;
        temp->next=NULL;
        delete temp;
    }

    void pop_back(){
        Node*temp=Head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        delete Tail;
        Tail=temp;
        Tail->next=NULL;
        
    }
};

void segregate(Node*&h){
    Node* evenStart = NULL;
    Node* evenEnd = NULL;
    Node* oddStart = NULL;
    Node* oddEnd = NULL;

    while(h != NULL){
        if(h->data % 2 == 0){
            if(evenStart == NULL){
                evenStart = h;
                evenEnd = evenStart;
            }else{
                evenEnd->next = h;
                evenEnd = evenEnd->next;
            }
        }else{
            if(oddStart == NULL){
                oddStart = h;
                oddEnd = oddStart;
            }else{
                oddEnd->next = h;
                oddEnd = oddEnd->next;
            }
        }
        h = h->next;
    }

    if(evenStart == NULL){
        evenStart = oddStart;
    }else{
        evenEnd->next = oddStart;
    }

    if(oddStart != NULL){
        oddEnd->next = NULL;
    }

    h = evenStart;
}
int main(){
    Slist l;
    for(int i=1;i<=10;i++){
        l.push_back(i);
    }
    l.PrintLL();
    segregate(l.Head);
    l.PrintLL();

    return 0;
}



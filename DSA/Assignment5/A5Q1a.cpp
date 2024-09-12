#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node():data(0),next(NULL){}
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

    void Delete(int pos){
        Node*prev=NULL;
        Node*Next=Head;
        for(int i=0;i<pos;i++){
            prev=Next;
            Next=Next->next;
        }
        prev->next=Next->next;
        Next->next=NULL;
        delete Next;

    }

    int search(int key){
        int pos=0;
        Node*temp=Head;
        while(temp!=NULL){
            if(temp->data==key){
                return pos;
            }
            temp=temp->next;
            pos++;
        }
        return -1;
    }

    void reverseLL(){
        Tail=Head;
        Node*prev=NULL;
        Node*curr=Head;
        Node*next;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        Head=prev;
    }

};

Node*merge(Node *Head1,Node*Head2){
    Slist ll;
    Node*temp1=Head1;
    Node*temp2=Head2;
    while(temp1!=NULL&&temp2!=NULL){
        if((temp1->data)<=(temp2->data)){
            ll.push_back(temp1->data);
            temp1=temp1->next;
        }else{
            ll.push_back(temp2->data);
            temp2=temp2->next;
        }
    }

    while(temp1!=NULL){
        ll.push_back(temp1->data);
        temp1=temp1->next;
    }

    while(temp2!=NULL){
        ll.push_back(temp2->data);
        temp2=temp2->next;
    }

    return ll.Head;
}
Node*merge2(Node *Head1,Node*Head2){
    Node*temp=NULL;
    Node*x=NULL;
    if(Head1->data<=Head2->data){
        temp=Head1;
        x=Head2;
    }else{
        temp=Head2;
        x=Head1;
        
    }
    
    
    Node* prev=temp;
    Node*curr=temp->next;

    while(curr!=NULL&&x!=NULL){
        if(x->data>=prev->data&&x->data<curr->data){
            prev->next=x;
            Node*t=x->next;
            x->next=curr;
            x=t;
            prev=prev->next;

        }else{
            prev=curr;
            curr=curr->next;
        }

        

    }

    if(x!=NULL){
        prev->next=x;
    }
    return temp;
       
}

int main(){
    // //Question 1

    // Slist l;
    // cout<<"Push_front :";
    // l.push_front(3);
    // l.push_front(2);
    // l.push_front(1);
    // l.PrintLL();
    // cout<<"Push_back :";
    // l.push_back(4);
    // l.push_back(5);
    // l.PrintLL();
    // cout<<"Insertion  :";
    // l.insert(10,3);
    // l.PrintLL();
    // cout<<"Pop_front :";
    // l.pop_front();
    // l.PrintLL();
    // cout<<"Pop_back :";
    // l.pop_back();
    // l.PrintLL();
    // cout<<"Delete :";
    // l.Delete(2);
    // l.PrintLL();
    // cout<<"Search (3):";
    // cout<<l.search(3)<<endl;

    // //Question 2

    // Slist ll;
    // cout<<"Linked List  :";
    // ll.push_back(1);
    // ll.push_back(5);
    // ll.push_back(9);
    // ll.push_back(8);
    // ll.PrintLL();
    // cout<<"Reversed Linked List :";
    // ll.reverseLL();
    // ll.PrintLL();

    // //Question 3

    Slist l1,l2,l3;

    cout<<"Linked List 1 :";
    l1.push_back(-9);
    l1.push_back(3);
    l1.PrintLL();

    cout<<"Linked List 2 :";
    l2.push_back(5);
    l2.push_back(7);
    l2.PrintLL();

    cout<<"MergedLinked List 1 :";
    l3.Head=merge2(l1.Head,l2.Head);
    l3.PrintLL();
    



    return 0;
}
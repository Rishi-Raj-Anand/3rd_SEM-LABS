// Write a program to detect a cycle in a linked list.
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



int main(){
    Node n5(5),n4(4,&n5),n3(3,&n4),n2(2,&n3),n1(1,&n2);
    n5.next=&n2;
    Node*Head=&n1;
    Node*slow=Head;
    Node*fast=Head;
    slow=slow->next;
    fast=fast->next->next;
    while(slow!=fast){
        if((fast==NULL||fast->next==NULL)){
            cout<<"NO cycle found !!";
            break;
        }
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            cout<<"Cycle found !!";
        }
        
    }

    return 0;
}
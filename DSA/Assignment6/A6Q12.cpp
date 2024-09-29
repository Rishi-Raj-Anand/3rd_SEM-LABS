/*Write a program to manage an emergency room queue using a linked list. Each node
represents a patient with attributes like patient ID, name, and emergency level. Patients
should be sorted by emergency level. Provide functions to add a patient, treat the next
patient, and display the queue.*/
//  Level 1 – Resuscitation (immediate life-saving intervention);  Level 2 – Emergency; Level 3 – Urgent; Level 4 – Semi-urgent; Level 5 – Non-urgent.

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class patient{
    
    public:
    static int ID;
    int p_id;
    string Name;
    int Emg;
    patient*Next;
    patient():Name("xxxxx"),Emg(0),Next(NULL){
        p_id=++ID;
    }
};
int patient:: ID=20240;
class Queue{
    patient* Head=NULL;
    public:
    void add(){
        patient*pNode=new patient;
        cout<<"Enter Patient Name :";
        cin>>pNode->Name;
        cout<<"Enter Emergency Level (1->5):";
        cin>>pNode->Emg;
        
        if(Head==NULL){
            Head=pNode;
        }else{
            patient*curr=Head;
            patient*prev=NULL;
            while(curr!=NULL){
                if(curr->Emg>pNode->Emg){
                    
                    if(prev==NULL){
                        pNode->Next=curr;
                        Head=pNode;
                        
                    }else{
                        pNode->Next=curr;
                        prev->Next=pNode;
                    }
                    
                    return;
                }
                prev=curr;
                curr=curr->Next; 
            }
            prev->Next=pNode;
        }

    }
    void treat(){
        patient*temp=Head;
        if(temp==NULL){
            cout<<"NO Patient left !!"<<endl;
        }else{
            Head=Head->Next;
            cout<<".....Patient....."<<endl;
            cout<<"ID :"<<temp->p_id<<endl;
            cout<<"Name :"<<temp->Name<<endl;
            cout<<"Emergency Level :"<<temp->Emg<<endl;
            delete temp;
            temp=NULL;
        }
    }
    void showQueue(){
        cout<<setiosflags(ios::left);
        cout<<"--------------QUEUE--------------"<<endl;
        patient*temp=Head;
        cout<<setiosflags(ios::left);
        cout<<setw(10)<<"ID"<<"  "<<setw(10)<<"NAME"<<"  "<<setw(10)<<"Emergency"<<endl;
        while(temp!=NULL){
            cout<<setw(10)<<temp->p_id<<"  "<<setw(10)<<temp->Name<<"  "<<setw(10)<<temp->Emg<<endl;
            temp=temp->Next;
        }
    }
    ~Queue(){
        patient*temp=NULL;
        while(temp!=NULL){
            temp=Head;
            Head=Head->Next;
            delete temp;
            

        }
    }
};

int main(){
    Queue Q1;
    bool c=1;
    while(c){
        cout<<"Enter\n'a':Add patient \n't':treat patient \n's':Show Queue \n"<<endl;
        cout<<"Your option ::";
        char x;
        cin>>x;
        cout<<endl;
        switch(x){
            case 'a':
                Q1.add();
                break;
            case 't':
                Q1.treat();
                break;
            case 's':
                Q1.showQueue();
                break;
            default :
                cout<<"Invalid input :";
                break;
        }
        cout<<"\n";
        cout<<"'1':continue '0:Exit ::";
        cin>>c;

    }

    return 0;
}
/*Create a linked list to manage inventory items for a small store. Each node should hold
information about the product, such as the product ID, name, quantity, and price. Provide
functions to add new products, delete products, and restock products.*/

#include<iostream>
#include<string>
using namespace std;

struct product{
    int id;
    string name;
    int quantity;
    float price;
    product*next;
    product():id(0),name("xxxx"),quantity(0),price(0),next(NULL){}
};

class store{
    product*Head=NULL;
    product*Tail=NULL;
    public:
    void addProduct(){
        product*np=new product;
        cout<<"\n";
        cout<<"Enter Product ID :";
        cin>>np->id;
        cout<<"Enter Product name :";
        cin>>np->name;
        cout<<"Enter Product price :";
        cin>>np->price;
        cout<<"Enter Product quantity :";
        cin>>np->quantity;
        if(Head==NULL){
            Head=np;
            Tail=np;
        }else{
            Tail->next=np;
            Tail=np;
        }
        
    }
    void delProduct(){
        cout<<"Enter Product ID :"<<endl;
        int x;
        cin>>x;
        product*prev=NULL;
        product*curr=Head;
        while(curr!=NULL){
            if(x==curr->id){
                if(prev==NULL){
                    Head=curr->next;
                }else{
                    prev->next=curr->next;

                }
                delete curr;
                curr=NULL;
                return;
            }
            prev=curr;
            curr=curr->next;
        }
        cout<<"ID not found";


    }

    void restock(){
        cout<<"Enter product id :" ;
        int x;
        cin>>x;
        product*temp=Head;
        while(temp!=NULL){
            if(temp->id==x){
                cout<<"\n";
                cout<<"Enter restock amount :";
                int reQ;
                cin>>reQ;
                temp->quantity+=reQ;
                return;
            }
            temp=temp->next;
            
        }
        cout<<"Id not found !!";
        
    }

    void showProduct(){
        cout<<"Enter product ID :";
        int x;
        cin>>x;
        product*temp=Head;
        while(temp!=NULL){
            if(temp->id==x){
                cout<<"\n";
                cout<<"Id :"<<temp->id<<endl;
                cout<<"Name :"<<temp->name<<endl;
                cout<<"Price :"<<temp->price<<endl;
                cout<<"Quantity :"<<temp->quantity<<endl;
                
                return; 
            }
            temp=temp->next;
            
        }
        cout<<"Id not found !!";
    }

    void showStock(){
        product*temp=Head;
        while(temp!=NULL){
            cout<<"\n";
            cout<<"Id :"<<temp->id<<endl;
            cout<<"Name :"<<temp->name<<endl;
            cout<<"Price :"<<temp->price<<endl;
            cout<<"Quantity :"<<temp->quantity<<endl;
            temp=temp->next;
        }

    }
};

int main(){
    store s1;
    bool c=1;
    while(c){
        cout<<"Enter\n'a':Add product \n'd':Delete Product \n'r':Restock \n's':Show product\n'l':Show all product\n"<<endl;
        cout<<"Your option ::";
        char x;
        cin>>x;
        cout<<endl;
        switch(x){
            case 'a':
                s1.addProduct();
                break;
            case 'd':
                s1.delProduct();
                break;
            case 's':
                s1.showProduct();
                break;
            case 'l':
                s1.showStock();
                break;
            case 'r':
                s1.restock();
                break;
            default :
                cout<<"Invalid input :";
                break;
        }
        cout<<"'1':continue '0:Exit ::";
        cin>>c;

    }

}
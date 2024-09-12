#include<iostream>
#include<string>
using namespace std;

int main(){
    string name;
    cout<<"Enter name to search :";
    cin>>name;
    string names[5]={"Rishi","Anand","Chitra","Raman","Raj"};
    for(int i=0;i<5;i++){
        if(names[i]==name){
            cout<<"Name found :"<<i;
            return 0;
        }
        
    }
    cout<<"Name not found";
    
    return 0;
}
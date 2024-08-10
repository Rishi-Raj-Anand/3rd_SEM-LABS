#include<iostream>
#include<conio.h>
using namespace std;
class name
{
private:
    char nam[15];
    int count=0;
public:
    void setname(){
        char a='s';
        
        cout<<"Enter your name: ";
        while(a!='\r'){
            a=getche();
            nam[count]=a;
            count++;
        }
        cout<<endl;
    }

    void getname(){
        for(int i=0;i<count-1;i++){
            cout<<nam[i];
        }
        
    }
};

int main(){
    name name1;
    name1.setname();
    name1.getname();
    

    return 0;
}
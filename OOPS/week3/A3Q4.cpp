
#include<iostream>
using namespace std;
class Rectangle{
    private:
    float l;
    float b;
    public:
    Rectangle():l(0),b(0)
    {
        cout<<"Default constructor called ..."<<endl;
    }
    Rectangle(int x,int y ):l(x),b(y)
    {
        cout<<"Parametrized constructor called ..."<<endl;
    }
    Rectangle(const Rectangle &c){
        l=c.l;
        b=c.b;
        cout<<"Copy Constructor called ..."<<endl;
    }
    ~Rectangle(){
        cout<<"Destructor called ..."<<endl;
    }


    void show(){
        cout<<"length :"<<l<<endl;
        cout<<"Breadth :"<<b<<endl;
        cout<<"Area :"<<l*b<<endl;
        cout<<"\n"<<endl;
    }


};


int main(){
    Rectangle a;
    a.show();
    Rectangle b(1,2);
    b.show();
    Rectangle c=b;
    c.show();
    return 0;
}

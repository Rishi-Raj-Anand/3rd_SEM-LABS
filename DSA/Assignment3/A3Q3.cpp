#include<iostream>
using namespace std;

int main(){
    int a,*b,**c;
    a=5;
    b=&a;
    c=&b;
    cout<<a<<endl;
    cout<<&a<<endl;
    cout<<b<<endl;
    cout<<*b<<endl;
    cout<<&b<<endl;
    cout<<c<<endl;
    cout<<*c<<endl;
    cout<<**c<<endl;

    return 0;
}


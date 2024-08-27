#include<iostream>
using namespace std;

int main(){
    int *b,a;
    a=5;
    b=&a;
    cout<<a<<endl;
    cout<<*b<<endl;
    *b=10;
    cout<<a<<endl;
    cout<<*b<<endl;
    
    return 0;
}
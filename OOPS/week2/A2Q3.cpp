#include<iostream>
using namespace std;
void swap(int &x,int &y){
    x=x+y;
    y=x-y;
    x=x-y;
}

int main(){
    int a,b;
    cout<<"Enter value of a and b :";
    cin>>a>>b;
    cout<<"Before swap :: a:"<<a<<" b:"<<b<<endl;
    swap(a,b);
    cout<<"After swap :: a:"<<a<<" b:"<<b<<endl;
    return 0;
}
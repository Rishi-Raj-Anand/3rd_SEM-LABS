#include<iostream>
using namespace std;

int main(){
    int a,n;
    int &b=a;
    cout<<"Enter value of a :";
    cin>>a;
    cout<<"a :"<<a<<endl;
    cout<<"Enter n :";
    cin>>n;
    cout<<"increasing value of b by "<<n<<"..."<<endl;
    b=b+n;
    cout<<"a :"<<a<<" b :"<<b<<endl;
    return 0;
}
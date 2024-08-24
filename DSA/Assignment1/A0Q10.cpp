#include<iostream>
using namespace std;
void isTriangle(float a,float b,float c){
    if((a+b+c)==180.0f){
        cout<<"Valid Triangle";
    }else{
        cout<<"Invalid Triangle";
    }
}
int main(){
float a,b,c;
cout<<"Enter angles of triangle :";
cin>>a>>b>>c;
isTriangle(a,b,c);
}
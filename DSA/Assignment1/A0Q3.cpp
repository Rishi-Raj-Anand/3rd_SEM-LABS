#include<iostream>
using namespace std;
int factorial(int num){
    int fac=1;
    for(int i=num;i>=1;i--){
        fac=fac*i;
    }
    return fac;
}

int main(){
    int num;
    cout<<"Enter number :";
    cin>>num;
    cout<<"factorial :"<<factorial(num);
    return 0;
}


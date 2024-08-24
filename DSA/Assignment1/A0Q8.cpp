#include<iostream>
using namespace std;
void isPrime(int num){
    bool prime=true;
    for(int i=2;i<num;i++){
        if(num%i==0){
            prime=false;
        }
    }
    if(prime){
        cout<<num<<" is a prime number";
    }else{
        cout<<num<<" is not a prime number";
    }
}

int main(){
    int num;
    cout<<"Enter number :";
    cin>>num;
    isPrime(num);
    return 0;
}


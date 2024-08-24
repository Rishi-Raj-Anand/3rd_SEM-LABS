#include<iostream>
using namespace std;
int sum(int num){
    int s=0;
    for(int i=1;i<=num;i++){
        s+=i;
    }
    return s;
}

int main(){
    int num;
    cout<<"Enter number :";
    cin>>num;
    cout<<"Sum of first "<<num<<" natural numbers :"<<sum(num);
    return 0;
}


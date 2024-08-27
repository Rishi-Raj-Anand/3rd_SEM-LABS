#include<iostream>
using namespace std;

int main(){
    float a=23.4,b=2.9,c=10,d=99.8,e=25.4;
    float *arr[5];
    arr[0]=&a;
    arr[1]=&b;
    arr[2]=&c;
    arr[3]=&d;
    arr[4]=&e;
    for(int i=0;i<5;i++){
        cout<<*arr[i]<<" ";
    }
    return 0;
}


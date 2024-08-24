#include<iostream>
using namespace std;
int LCM(int a,int b){
    int l=a*b;
    int min;
    if(a>=b){
        min=b;
    }else{
        min=a;
    }
    for(int i=2*min;i<=l;i++){
        if(((i%a) +(i%b))==0){
            return i;
        }
    }
    return l;
}
int main(){
    int a,b;
    cout<<"Enter two numbrers :";
    cin>>a>>b;
    cout<<"LCM of "<<a<<" and "<<b<<" is "<<LCM(a,b);
    return 0;
}
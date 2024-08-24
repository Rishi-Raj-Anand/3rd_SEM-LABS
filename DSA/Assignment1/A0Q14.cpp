#include<iostream>
using namespace std;
int countDigit(int num){
    int count=0 ;
    while(num!=0){
        count++;
        num/=10;
    }
   return count;
}

int power(int n,int m){
    int p=1;
    while(m!=0){
        p=p*n;
        m--;
    }
    return p;
}

void  isArmstrongNum(int num,int n){
    int nnum=num;
    int sum=0;
    int d;
    while(num!=0){
        d=num%10;
        sum=sum+power(d,n);
        num/=10;
    }
    
    if(sum==nnum){
        cout<<"Armstrong Number";
    }
    else{
        cout<<"Not a Armstrong Number";
    }

}


int main(){
    int num;
    cout<<"Enter Number :";
    cin>>num;
    isArmstrongNum(num,countDigit(num));
    return 0;
}
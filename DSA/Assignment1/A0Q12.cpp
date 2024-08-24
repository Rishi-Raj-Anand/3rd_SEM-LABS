#include<iostream>
using namespace std;
int reverseNum(int num){
    int rnum=0;
    int re;
    while(num!=0){
        re=num%10;
        rnum=rnum*10+re;
        num/=10;
    }
    return rnum;

}
int main(){
    int num;
    cout<<"Enter Number :";
    cin>>num;
    cout<<"Reversed number :"<<reverseNum(num);
}
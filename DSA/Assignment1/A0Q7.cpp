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
void isPalindrome(int n){
    if(n==reverseNum(n)){
        cout<<n<<" is a palindrome";
    }else{
        cout<<n<<" is not a palindrome";
    }
}


int main(){
    int num;
    cout<<"Enter number :";
    cin>>num;
    isPalindrome(num);
    return 0;
}


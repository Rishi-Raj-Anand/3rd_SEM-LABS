#include<iostream>
using namespace std;
bool palindrome(string &str){
    int s=0,e=str.length()-1;
    while(s<=e){
        if(str[s]!=str[e]){
            return false;
        };
        s++;
        e--;
    }
    return true;
}

int main(){
    cout<<"Enter string :";
    string str1;
    cin>>str1;
    cout<<"Palindrome :"<<palindrome(str1);
    return 0;
}
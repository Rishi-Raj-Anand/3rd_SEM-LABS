#include<iostream>
using namespace std;
void reverse(string &str){
    int s=0,e=str.length()-1;
    while(s<e){
        char temp=str[s];
        str[s]=str[e];
        str[e]=temp;
        s++;
        e--;
    }
}

int main(){
    cout<<"Enter string :";
    string str1;
    cin>>str1;
    reverse(str1);
    cout<<"Reversed :"<<str1;
    return 0;
}
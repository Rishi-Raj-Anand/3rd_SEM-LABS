#include<iostream>
#include<string>
using namespace std;
void concat(string &str1,string &str2){
    str1=str1+str2;
}

int main(){
    cout<<"Enter string 1:";
    string str1;
    cin>>str1;

    cout<<"Enter string 2:";
    string str2;
    cin>>str2;

    cout<<"Concatenation :";
    concat(str1,str2);
    cout<<str1;
    

    return 0;
}
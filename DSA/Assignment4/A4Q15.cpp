#include<iostream>
#include<string>
using namespace std;

void replace(string &str,char c,char r){
    for (int i=0;i<str.length();i++){
        if(str[i]==c){
            str[i]=r;
        }
    }
}

int main(){
    cout<<"Enter string 1:";
    string str1;
    getline(cin,str1);
    cout<<"Enter character to be replaced :";
    char c;
    cin>>c;
    cout<<"Enter character to replace :";
    char r;
    cin>>r;
    replace(str1,c,r);
    cout<<"Replaced :"<<str1;


    return 0;
}
#include<iostream>
#include<string>
using namespace std;
void Upper(string &str){
    for(int i=0;i<str.length();i++){
        if(str[i]>='a'&&str[i]<='z'){
            str[i]=char(int(str[i]-'a')+'A');
        }
        
    }
}

int main(){

    cout<<"Enter string :";
    string str1;
    cin>>str1;
    Upper(str1);

    cout<<"Uppercase :"<<str1;
    return 0;
}
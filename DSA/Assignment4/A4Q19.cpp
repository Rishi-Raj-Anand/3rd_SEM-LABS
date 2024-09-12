#include<iostream>
using namespace std;
void nonrepchar(string str){
    int freq[26]={0};
    for(int i=0;i<str.length();i++){
        freq[int(str[i]-'a')]++;
    }
    for(int i=0;i<str.length();i++){
        if(freq[str[i]-'a']==1){
            cout<<"char :"<<str[i]<<endl;
            cout<<"Position :"<<i<<endl;
            return;
        }
    }
}

int main(){
    cout<<"Enter string 1:";
    string str1;
    cin>>str1;
    nonrepchar(str1);
    return 0;
}
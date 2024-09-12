#include<iostream>
using namespace std;

void removeDup(string &str){
    int freq[26]={0};
    for(int i=0;i<str.length();i++){
        freq[int(str[i]-'a')]++;
    }
    string str2="";
    for(int i=0;i<str.length();i++){
        if(freq[str[i]-'a']>0){
            str2+=str[i];
            freq[str[i]-'a']=0;
        }
    }
    cout<<str2<<endl;
}

int main(){
    cout<<"Enter string 1:";
    string str1;
    cin>>str1;
    removeDup(str1);
    return 0;
}
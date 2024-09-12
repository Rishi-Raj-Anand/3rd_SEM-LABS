#include<iostream>
using namespace std;
bool checkSubstr(string s1,string s2){
    for(int i=0;i<s1.length();i++){
        for(int j=0;j<=s1.length();j++){
            if(s1.substr(i,j-i)==s2){
                return true;
            }

        }
        
    }
    return false;
}

int main(){
    cout<<"Enter string 1:";
    string str1;
    cin>>str1;

    cout<<"Enter string 2:";
    string str2;
    cin>>str2;

    cout<<"is Substring :"<<checkSubstr(str1,str2);
    return 0;
}
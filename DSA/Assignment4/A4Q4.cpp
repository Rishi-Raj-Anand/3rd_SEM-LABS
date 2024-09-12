#include<iostream>
#include<string>
using namespace std;
bool compare(string s1,string s2){
    if(s1.length()!=s2.length()){
        return false;
    }else{
        int n=s1.length();
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                return false;
            }
        }
        return true;
    }
}


int main(){
    cout<<"Enter string 1:";
    string str1;
    cin>>str1;

    cout<<"Enter string 2:";
    string str2;
    cin>>str2;

    cout<<"Compare :"<<compare(str1,str2);

    return 0;
}
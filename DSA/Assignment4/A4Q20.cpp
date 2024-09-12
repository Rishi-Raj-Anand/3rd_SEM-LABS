#include<iostream>
using namespace std;
bool isPalindrome(string &str){
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
void longestPalindrome(string str){
    int hlen=0;
    string longest="";
    for(int i=0;i<str.length();i++){
        for(int j=0;j<=str.length();j++){
            string sub=str.substr(i,j-i);
            if(isPalindrome(sub)){
                if(sub.length()>hlen){
                    longest=sub;
                    hlen=sub.length();
                }

            }
        }
        
    }
    cout<<"Longest palindrome :"<<longest<<endl;
}


int main(){
    cout<<"Enter string 1:";
    string str1;
    cin>>str1;
    longestPalindrome(str1);
    return 0;
}
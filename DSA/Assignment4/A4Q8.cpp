#include<iostream>
using namespace std;
char HighFreq(string str){
    int freq[26]={0};
    for(int i=0;i<str.length();i++){
        freq[int(str[i]-'a')]++;
    }
    int high=0;
    char HC;
    for(int i=0;i<26;i++){
        if(freq[i]>high){
            high=freq[i];
            HC=char(i+'a');
        }
    }
    return HC;

}

int main(){
    cout<<"Enter string :";
    string str1;
    cin>>str1;

    cout<<"Highest frequency character :"<<HighFreq(str1);
    return 0;
}

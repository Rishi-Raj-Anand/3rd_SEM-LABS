#include<iostream>
using namespace std;
void Freq(string str){
    int freq[26]={0};
    for(int i=0;i<str.length();i++){
        freq[int(str[i]-'a')]++;
    }

    for(int i=0;i<26;i++){
        if(freq[i]!=0){
            cout<<char(i+'a')<<" : "<<freq[i]<<endl;
        }
        
    }

}

int main(){
    cout<<"Enter string :";
    string str1;
    cin>>str1;
    Freq(str1);
    return 0;
}

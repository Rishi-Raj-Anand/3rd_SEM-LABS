#include<iostream>
#include<string>
using namespace std;
int countWords(string str){
    int count =1;
    for(int i=0;i<str.length();i++){
        if(str[i]==' '){
            count++;
        }
    }
    return count;
}

int main(){
    cout<<"Enter string 1:";
    string str1;
    getline(cin,str1);
    

    cout<<"Word count :"<<countWords(str1);

    return 0;
}
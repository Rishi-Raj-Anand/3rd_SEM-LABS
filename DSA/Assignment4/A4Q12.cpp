#include<iostream>
#include<string>
using namespace std;
void printWords(string str){
    for(int i=0;i<str.length();i++){
        if(str[i]!=' '){
            cout<<str[i];
            
        }else{
            cout<<"\n";
        }
    }
}

int main(){
    cout<<"Enter string 1:";
    string str1;
    getline(cin,str1);
    

    cout<<"Words :"<<endl;
    printWords(str1);

    return 0;
}
#include<iostream>
#include<string>
using namespace std;

void sort(string &str){
    for (int i=0;i<str.length()-1;i++){
        for(int j=0;j<str.length()-1-i;j++){
            if(str[j+1]<str[j]){
                swap(str[j],str[j+1]);
            }

        }
    }
}

int main(){
    cout<<"Enter string 1:";
    string str1;
    getline(cin,str1);
    sort(str1);
    cout<<"sorted :"<<str1;


    return 0;
}
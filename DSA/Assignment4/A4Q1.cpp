#include<iostream>
using namespace std;
int length(char* str){
    int count=0;
    while(*str!='\0'){
        count++;
        str+=1;
    }
    return count;
}

int main(){
    char name[20];
    cout<<"Enter name :";
    cin>>name;
    cout<<"Length :"<<length(name);
    return 0;
}
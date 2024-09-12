#include<iostream>
#include<cstring>
using namespace std;
void copy(char* dest,char*src){
    strcpy(dest,src);
}
int main(){
    char name[20];
    cout<<"Enter Name :";
    cin>>name;
    char cname[20];
    copy(cname,name);
    cout<<cname;
    
    return 0;
}
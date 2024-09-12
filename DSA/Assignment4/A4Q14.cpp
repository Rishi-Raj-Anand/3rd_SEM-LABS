#include<iostream>
#include<string>
using namespace std;
void larWords(string str){
    string temp="";
    string lar="";
    int h=0, hmax=0;

    for(int i=0;i<str.length();i++){
        if(str[i]==' '){
            if(h>hmax){
                hmax=h;
                lar=temp;

            }
            h=0;
            temp="";
        }else{
            temp=temp+str[i];
            h++;
        }

    }
    if(h>hmax){
    hmax=h;
    lar=temp;

    }
    cout<<"Largest word :"<<lar<<endl;
    cout<<"size :"<<hmax;
}
    

int main(){
    cout<<"Enter string 1:";
    string str1;
    getline(cin,str1);
    
    larWords(str1);

    return 0;
}
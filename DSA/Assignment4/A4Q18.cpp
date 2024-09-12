#include<iostream>
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
bool isAnagram(string str1,string str2){
    sort(str1);
    sort(str2);
    if(str1==str2){
        return true;
    }
    return false;

}

int main(){
    cout<<"Enter string 1:";
    string str1;
    cin>>str1;

    cout<<"Enter string 2:";
    string str2;
    cin>>str2;

    cout<<"Is Anagram :"<<isAnagram(str1,str2);
    

    return 0;
}
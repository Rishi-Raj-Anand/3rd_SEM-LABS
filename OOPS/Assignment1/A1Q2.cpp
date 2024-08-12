#include<iostream>
using namespace std;
int main(){
    char arr[20]={'R','i','s','h','i'};
    int n=sizeof(arr)/sizeof(char);
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    return 0;
}
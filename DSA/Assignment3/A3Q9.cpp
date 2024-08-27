#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char s[]="Rishi";
    int n=strlen(s);
    char *ptre=s+(n-1);
    char *ptrs=s;
    cout<<"String : "<<s<<endl;
    while(ptrs<ptre){
        char c;
        c=*ptrs;
        *ptrs=*ptre;
        *ptre=c;
        ptrs++;
        ptre--;
    }
    cout<<"Reversed : "<<s;
    return 0;
}


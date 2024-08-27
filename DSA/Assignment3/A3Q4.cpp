#include<iostream>
using namespace std;
void Swap(int *x,int *y){
    int c;
    c=*x;
    *x=*y;
    *y=c;

}
int main(){
    int a=5,b=8;
    int *x=&a,*y=&b;
    cout<<a<<" "<<b<<endl;
    Swap(x,y);
    cout<<a<<" "<<b<<endl;
    return 0;
}


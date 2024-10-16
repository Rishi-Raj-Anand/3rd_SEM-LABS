#include<iostream>
using namespace std;

int main(){

    return 0;
}

complex& operator =(const complex& c2){
    if(this!=&c2){
        *this->real=c2.real;
        *this->img=c2.img
    }
    return *this;
    
}
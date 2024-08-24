#include<iostream>
using namespace std;
void checkTriangle(float a,float b,float c){
    if(a==b && b==c){
        cout<<"Eqilateral Triangle"<<endl;
    }
    else if(a==b){
        cout<<"Isosceles Triangle"<<endl;
    }
    else if(b==c){
        cout<<"Isosceles Triangle"<<endl;
    }
    else if(a==c){
        cout<<"Isosceles Triangle"<<endl;
    }
    else{
        cout<<"Scalene Triangle"<<endl;
    }
}
int main(){
    float a,b,c;
    cout<<"Enter sides of triangle :";
    cin>>a>>b>>c;
    checkTriangle(a,b,c);
}
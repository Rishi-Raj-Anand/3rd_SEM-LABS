#include<iostream>
using namespace std;
void checkQuadrant(float x,float y){
    if(x>0 && y>0){
        cout<<"Firat Quadrant";
    }
    else if(x<0 && y>0){
        cout<<"Second Quadrant";
    }else if (x<0 && y<0){
        cout<<"Third Quadrant";
    }else if(x>0 && y<0){
        cout<<"Fourth Quadrant ";
    }else if(x==0 && y==0){
        cout<<"Origin";
    }
}
int main(){
    float x,y;
    cout<<"Enter coordiantes :";
    cin>>x>>y;
    cout<<"Coodiantes ("<<x<<","<<y<<") is in ";
    checkQuadrant(x,y);
}
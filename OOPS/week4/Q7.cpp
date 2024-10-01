// 7.Implement binary operator overloading using both member and friend functions for user-defined classes.
#include<iostream>
using namespace std;
class complex{
    private:
    float real;
    float img;
    public:
    complex():real(0),img(0){};
    complex(float r,float i):real(r),img(i){}
    complex(float r):real(r),img(0){}

    complex operator+(complex &b){
        complex temp;
        temp.real=real+b.real;
        temp.img=img+b.img;
        return temp;
    }
    friend complex operator +(complex a,complex b);

    void show()const{
        cout<<real<<"+"<<img<<"j"<<endl;
    }
};
complex operator + (complex a,complex b){
    complex temp;
    temp.real=a.real+b.real;
    temp.img=a.img+b.img;
    return temp;
}
int main(){
    complex c1(2,3),c2;
    c1.show();
    c2=10.0+c1;
    c2.show();
    c2=c2+10;
    c2.show();
    return 0;
}


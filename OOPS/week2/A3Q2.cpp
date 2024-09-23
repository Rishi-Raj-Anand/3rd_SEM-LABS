#include<iostream>
using namespace std;
class Complex{
    private:
    int real;
    int img;
    public:
    Complex(int r,int i):real(r),img(i){}
    Complex():real(0),img(0){}
    void setvalue(){
        cout<<"Enter real part :";
        cin>>real;
        cout<<"Enter imag part :";
        cin>>img;
    }
    void getnum(){
        cout<<real<<" + "<<img<<"j"<<endl;
    }
    Complex operator +(Complex c2){
        Complex c3;
        c3.real=real+c2.real;
        c3.img=img+c2.img;
        return c3;

    }

};

int main(){
    Complex c1(1,3),c2,c3;
    c2.setvalue();
    cout<<"Num 1 :";
    c1.getnum();
    cout<<"Num 2 :";
    c2.getnum();
    cout<<"Addition :";
    c3=c1+c2;
    c3.getnum();
    return 0;
}
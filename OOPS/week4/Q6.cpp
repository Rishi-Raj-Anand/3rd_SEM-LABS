// 6.Implement unary operator overloading using both member and friend functions for user-defined classes.
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
    complex operator ++(){
        ++real;
        ++img;
        return *this;
    }
    complex operator ++(int){
        complex s;
        s.real=real;
        s.img=img;
        real++;
        img++;
        return s;
    }
   friend complex operator ~(complex&c){
        complex temp;
        temp.real = -c.real;
        temp.img = -c.img;
        return temp;
    }


    void show()const{
        cout<<real<<"+"<<img<<"j"<<endl;
    }
};

int main(){
    complex c1;
    c1.show();
    ++c1;
    c1.show();
    c1++;
    c1.show();
    c1= ~c1;
    c1.show();

    return 0;
}


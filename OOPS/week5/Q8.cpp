//  Develop programs to demonstrate the conversion from basic to custom data types and vice versa

#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;
public:
    
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    
    operator double() const {
        return real;
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    
    double d = 5.0;
    Complex c1 = d;  
    c1.display();  

    
    Complex c2(3.0, 4.0);
    double d2 = c2;  
    cout << "d2: " << d2 << endl;  
    cout<<double(c2);
    return 0;
}
#include<iostream>
class OuterClass {
private:
    int x = 10;

public:
    class InnerClass {
        int x=3;
    public:
        void print() {
            std::cout << "This is an inner class" << std::endl;
            std::cout << "Value of x: " << x << std::endl;
        }
    };
};
int main() {
    // OuterClass outer;
    OuterClass::InnerClass inner;
    inner.print();
    return 0;
}
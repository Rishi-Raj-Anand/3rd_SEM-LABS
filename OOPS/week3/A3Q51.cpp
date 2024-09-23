#include <iostream>
using namespace std;

class MyClass {
private:
    int data;
public:
    MyClass(int val) : data(val) {}

    friend void display(const MyClass& obj);
};

void display(const MyClass& obj) {
    cout << "Data: " << obj.data << endl;
}

int main() {
    MyClass obj(10);
    display(obj);  
    return 0;
}
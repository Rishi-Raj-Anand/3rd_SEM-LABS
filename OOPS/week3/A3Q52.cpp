#include <iostream>
using namespace std;

class MyClass {
private:
    int data;
public:
    MyClass(int val) : data(val) {}
    friend class MyFriendClass;
};

class MyFriendClass {
public:
    void display(const MyClass& obj) {
        cout << "Data: " << obj.data << endl;
    }
};

int main() {
    MyClass obj(10);
    MyFriendClass friendObj;
    friendObj.display(obj);  
    return 0;
}
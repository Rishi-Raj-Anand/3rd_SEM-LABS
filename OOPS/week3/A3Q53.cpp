#include <iostream>
using namespace std;

class EmptyClass {
    
};

int main() {
    EmptyClass obj;
    cout << "Size of EmptyClass: " << sizeof(obj) << endl;
    return 0;
}
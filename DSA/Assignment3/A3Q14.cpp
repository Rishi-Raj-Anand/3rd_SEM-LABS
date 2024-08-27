#include <iostream>
using namespace std;
float add(float a, float b) {
    return a + b;
}

int main() {
    float (*ptr)(float, float);
    ptr = &add;
    float result = ptr(5.0, 3.0);

    cout << "Result: " << result <<endl;

    return 0;
}
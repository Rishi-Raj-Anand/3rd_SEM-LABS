#include <iostream>
using namespace std;

int calculateArea(int length, int width) {
    return length * width;
}

int calculatePerimeter(int length, int width) {
    return 2 * (length + width);
}

int main() {
    int length;
    int width;
    cout<<"Enter length of Rectangle :";
    cin>>length;
    cout<<"Enter width of Rectangle :";
    cin>>width;

    int area = calculateArea(length, width);
    int perimeter = calculatePerimeter(length, width);

    cout << "Area: " << area << endl;
    cout << "Perimeter: " << perimeter << endl;

    return 0;
}
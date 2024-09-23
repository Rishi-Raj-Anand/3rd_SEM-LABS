#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void modifyArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = arr[i] * 2;
    }
}

int main() {
    cout<<"Enter size of array :";
    int size;
    cin>>size;
    int arr[size];
    cout<<"Enter "<<size<<" integers :";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    

    cout << "Original Array: ";
    printArray(arr, size);

    modifyArray(arr, size);

    cout << "Modified Array: ";
    printArray(arr, size);

    return 0;
}
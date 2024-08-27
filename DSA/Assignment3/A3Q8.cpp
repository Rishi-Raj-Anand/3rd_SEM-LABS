#include<iostream>
using namespace std;
int* getEvenNumbers(int arr[], int size, int& newSize) {
    newSize = 0;
    for (int i = 0 ; i < size; i++) {
        if (arr[i] % 2 == 0) {
            newSize++;
        }
    }

    int* evenArr = new int[newSize];
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            evenArr[j++] = arr[i];
        }
    }

    return evenArr;
}

int main() {
    int size;
    cout<<"Enter size of array:";
    cin>>size;
    cout<<"Enter array of size "<<size<<" :";
    int arr[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
   
    int newSize;
    int* evenArr = getEvenNumbers(arr, size, newSize);

    cout<<"Even Numbers :";
    for (int i = 0; i < newSize; i++) {
        cout << evenArr[i] << " ";
    }
    cout << endl;

    delete[] evenArr;
    return 0;
}


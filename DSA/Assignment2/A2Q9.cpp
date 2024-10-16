#include<iostream>
using namespace std;

int main(){
    int arr[2][2];
    int n=2;
    cout<<"Enter values of (2X2) matrix :";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"Given Matrix :"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    int det=arr[0][0]*arr[1][1]-arr[0][1]*arr[1][0];
    cout<<"Determinant :"<<det;
}

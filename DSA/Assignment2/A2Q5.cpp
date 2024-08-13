#include<iostream>
using namespace std;

int main(){
    int rows21,cols21;
    cout<<"Enter rows21 and cols21:";
    cin>>rows21>>cols21;
    int arr[rows21][cols21];
    cout<<"Enter values of matrix :";
    for(int i=0;i<rows21;i++){
        for(int j=0;j<cols21;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"Given Matrix :"<<endl;
    for(int i=0;i<rows21;i++){
        for(int j=0;j<cols21;j++){
            cout<<setw(3)<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    int rows2,cols2;
    float value;
    cout<<"Enter rows2 and cols2:";
    cin>>rows2>>cols2;
    int arr[rows2][cols2];
    cout<<"Enter values of matrix :";
    for(int i=0;i<rows2;i++){
        for(int j=0;j<cols2;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"Given Matrix :"<<endl;
    for(int i=0;i<rows2;i++){
        for(int j=0;j<cols2;j++){
            cout<<setw(3)<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int rows,cols;
    float value;
    cout<<"Enter rows and cols:";
    cin>>rows>>cols;
    int arr[rows][cols];
    cout<<"Enter values of matrix :";
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"Given Matrix :"<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<setw(3)<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Enter scalar value :";
    cin>>value;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            arr[i][j]*=value;
        }
    }
      
    cout<<"New Matrix(Scalar multiplication):"<<endl;;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<setw(3)<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
      
    return 0;
}
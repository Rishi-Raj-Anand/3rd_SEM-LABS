#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cout<<"Enter n for Matrix (nXn) :";
    cin>>n;
    int arr[n][n];
    cout<<"Enter values of matrix "<<n<<" X "<<n<<" :";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"Given Matrix :"<<endl;
    bool isSymmetric=true;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]!=arr[j][i]){
                isSymmetric=false;
            }
            cout<<setw(3)<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    if(isSymmetric){
        cout<<"\nSymmetrix Matrix";
    }
    else{
        cout<<"\nNot a Symmetrix Matrix";
    }

    return 0;
}
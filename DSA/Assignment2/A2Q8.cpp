#include<iostream>
#include<iomanip>
using namespace std;

int main()
{   int n;
    float trace=0;
    cout<<"Enter size of matrix (nXn):";
    cin>>n;
    float arr[n][n];
    cout<<"Enter values of matrix :";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"Given Matrix :"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<setw(3)<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        trace+=arr[i][i];
    }

    cout<<"\nTrace :"<<trace;
    return 0;
}
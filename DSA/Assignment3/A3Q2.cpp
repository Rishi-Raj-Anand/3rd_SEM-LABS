#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter size of array:";
    cin>>n;
    cout<<"Enter array of size "<<n<<" :";
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int *x=arr;
    for(int i=0;i<n;i++){
        cout<<(x+i)<<" ";
        cout<<*(x+i)<<endl;;
    }

    return 0;
}


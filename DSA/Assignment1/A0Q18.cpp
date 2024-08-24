#include<iostream>
using namespace std;

int sum(int arr[],int n){
    int s=0;
    for(int i=0;i<n;i++){
        s+=arr[i];
    }
    return s;
}

int main(){
    int n;
    cout<<"Enter size of array :";
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" numbers :";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Sum :"<<sum(arr,n);

    return 0;
}
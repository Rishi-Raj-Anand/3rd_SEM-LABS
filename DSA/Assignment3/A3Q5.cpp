#include<iostream>
using namespace std;
void Maximum(int *arr,int *m,int n){
    for(int i=0;i<n;i++){
        if(arr[i]>*m){
            *m=arr[i];
        }
    }
}

int main(){
    int n;
    cout<<"Enter size of array:";
    cin>>n;
    cout<<"Enter array of size "<<n<<" :";
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int max=0;
    Maximum(arr,&max,n);
    cout<<"Maximum Element :"<<max;

    return 0;
}


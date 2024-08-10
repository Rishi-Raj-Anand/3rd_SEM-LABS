#include<iostream>
using namespace std;
int SecondlargestNum(int *arr,int n){
    int lar=INT_MIN;
    int Slar=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>lar){
            lar=arr[i];
        }
    }

    for(int i=0;i<n;i++){
        if(arr[i]>Slar && arr[i]!=lar){
            Slar=arr[i];
        }
    }
    
    return Slar;
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
    cout<<"Second Largest number is "<<SecondlargestNum(arr,n);

    return 0;
}
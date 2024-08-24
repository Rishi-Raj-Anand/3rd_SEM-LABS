#include<iostream>
using namespace std;
void Duplicates(int *arr,int n){
    int max=INT_MIN;
    int min=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
        if(arr[i]<min){
            min=arr[i];
        }
    }
    int range=max-min;

    int fre[range+1]={0};
    for(int i=0;i<n;i++){
        fre[arr[i]-min]++;
    }
    cout<<"Duplicate elements :";
    for(int i=0;i<range+1;i++){
        if(fre[i]>1){
            cout<<i+min<<" ";
        }
       
    }



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
    Duplicates(arr,n);
    

    return 0;
}
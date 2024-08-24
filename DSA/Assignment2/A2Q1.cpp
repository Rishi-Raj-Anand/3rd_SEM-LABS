#include<iostream>
using namespace std;
void countFreq(int arr[],int n){
    
    int min=INT_MAX;
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]<min){
            min=arr[i];
        }
        if(arr[i]>max){
            max=arr[i];
        }
    }
    int range=max-min+1;
    int freq[range]={0};
    for(int i=0;i<n;i++){
        freq[arr[i]-min]++;
    }
    for(int i=0;i<range;i++){
        if(freq[i]!=0){
            cout<<i+min<<":"<<freq[i]<<endl;
        }
        
    }
}

int main(){
    int n;
    cout<<"Enter size of array :";
    cin>>n;
    cout<<"Enter array :";
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    countFreq(arr,n);
    return 0;
}
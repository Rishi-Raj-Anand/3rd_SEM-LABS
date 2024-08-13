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
    int arr[]={5,9,1,45,5,44,71,2,2,8,3,7,3,6,5,4};
    int n=sizeof(arr)/sizeof(int);
    countFreq(arr,n);
    return 0;
}
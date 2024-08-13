#include<iostream>
#include<algorithm>
using namespace std;

void statistics(int arr[],int n){
    sort(arr,arr+n);
    float sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    float mean=sum/n;
    float median=0;
    if(n%2==0){
        int medianidx=(n/2);
        median=(arr[medianidx]+arr[medianidx-1])/2;
    }else{
        median=arr[int(n/2)];
    }
    int range=arr[n-1]-arr[0]+1;
    int freq[range]={0};
    for(int i=0;i<n;i++){
        freq[arr[i]-arr[0]]++;
    }
    int modef=0;
    int mode=0;
    for(int i=0;i<range;i++){
        if(freq[i]>modef){
            modef=freq[i];
            mode=i+arr[0];
        }
    }

    cout<<"MEAN :"<<mean<<endl;
    cout<<"MEDIAN :"<<median<<endl;
    cout<<"MODE :"<<mode<<endl;
}

int main(){
    int arr[]={5,1,5,3,8,1,1,2,9,6,2,2,2,2,2,2,2};
    int n=sizeof(arr)/sizeof(int);
    statistics(arr,n);
    return 0;
}


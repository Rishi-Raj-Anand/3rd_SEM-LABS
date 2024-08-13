#include<iostream>
using namespace std;
void findCommon(int arr1[],int n,int arr2[], int m){
    int min=INT_MAX;
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr1[i]<min){
            min=arr1[i];
        }
        if(arr1[i]>max){
            max=arr1[i];
        }
    }
    for(int i=0;i<m;i++){
        if(arr2[i]<min){
            min=arr2[i];
        }
        if(arr2[i]>max){
            max=arr2[i];
        }
    }

    int range=max-min+1;
    int freq1[range]={0};
    int freq2[range]={0};

    for(int i=0;i<n;i++){
        freq1[arr1[i]-min]++;
    }
    for(int i=0;i<m;i++){
        freq2[arr2[i]-min]++;
    }
    cout<<"Common Elements: ";
    for(int i=0;i<range;i++){
        if(freq1[i]>0&&freq2[i]>0){
            cout<<i+min<<" ";
        }
    }

}

int main(){
    int arr1[]={1,2,11,2,3,8,5,3};
    int n=sizeof(arr1)/sizeof(int);
    int arr2[]={1,86,36,2,3,5};
    int m=sizeof(arr2)/sizeof(int);
    findCommon(arr1,n,arr2,m);
    return 0;
}

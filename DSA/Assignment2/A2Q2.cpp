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
    int n1;
    cout<<"Enter size of first array :";
    cin>>n1;
    cout<<"Enter first array :";
    int arr1[n1];
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
    }
    int n2;
    cout<<"Enter size of second array :";
    cin>>n2;
    cout<<"Enter second array :";
    int arr2[n2];
    for(int i=0;i<n2;i++){
        cin>>arr2[i];
    }
    findCommon(arr1,n1,arr2,n2);
    return 0;
}

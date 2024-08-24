#include<iostream>
using namespace std;
int largestNum(int *arr,int n){
    int lar=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>lar){
            lar=arr[i];
        }
    }
    return lar;

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
    cout<<"Largest number is "<<largestNum(arr,n);

    return 0;
}
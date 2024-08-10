#include<iostream>
using namespace std;
void ReverseArray(int *arr,int n){
    
    int i=0,j=n-1;
    while(i<=j){
        int x;
        x=arr[i];
        arr[i]=arr[j];
        arr[j]=x;
        i++;
        j--;
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
    ReverseArray(arr,n);
    cout<<"Reversed array :";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
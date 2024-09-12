#include<iostream>
using namespace std;
void cal(int *arr,int *n){
    int sum=0;
    for(int i=0;i<*n;i++){
        sum+=arr[i];
    }

    cout<<"Sum :"<<sum<<endl;
    cout<<"Average :"<<float(sum)/(*n);
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

    cal(arr,&n);
    return 0;
}


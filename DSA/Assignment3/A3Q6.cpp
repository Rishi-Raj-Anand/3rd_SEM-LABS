#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
    int n;
    cout<<"Enter size of array:";
    cin>>n;
    int *ptr=(int *)malloc(sizeof(int)*n);
    cout<<"Enter array of size "<<n<<" :";
    for(int i=0;i<n;i++){
        cin>>*(ptr+i);
    }
    cout<<"\nGiven array :";
    for(int i=0;i<n;i++){
        cout<<*(ptr+i)<<" ";
    }
    free(ptr);
    return 0;
}


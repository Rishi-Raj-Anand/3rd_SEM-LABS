#include<iostream>
using namespace std;

int main(){
    int n,m;
    cout<<"Enter number of rows : ";
    cin>>n;
    cout<<"Enter number of columns :";
    cin>>m;
    int matrix[n][m];
    cout<<"Enter your matrix :"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    cout<<"Given matrix :"<<endl;
    for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<"\n";
        }
        return 0;
}

#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    char con='Y';
    while(con!='N'){
        int rows1,cols1;
    cout<<"Enter rows1 and cols1:";
    cin>>rows1>>cols1;
    float arr1[rows1][cols1];
    cout<<"Enter values of matrix 1 :";
    for(int i=0;i<rows1;i++){
        for(int j=0;j<cols1;j++){
            cin>>arr1[i][j];
        }
    }
    cout<<"Given Matrix 1 :"<<endl;
    for(int i=0;i<rows1;i++){
        for(int j=0;j<cols1;j++){
            cout<<setw(4)<<arr1[i][j]<<" ";
        }
        cout<<endl;
    }

    int rows2,cols2;
    cout<<"Enter rows2 and cols2:";
    cin>>rows2>>cols2;
    float arr2[rows2][cols2];
    cout<<"Enter values of matrix 2 :";
    for(int i=0;i<rows2;i++){
        for(int j=0;j<cols2;j++){
            cin>>arr2[i][j];
        }
    }
    cout<<"Given Matrix 2 :"<<endl;
    for(int i=0;i<rows2;i++){
        for(int j=0;j<cols2;j++){
            cout<<setw(4)<<arr2[i][j]<<" ";
        }
        cout<<endl;
    }

    char op;
    cout<<"Enter operation (+/-/*):";
    cin>>op;
    if(op=='+'||op=='-'){
        if(rows1==rows2&&cols1==cols2){
        switch(op){
            case '+':
            {   cout<<"\nAddition :"<<endl;
                for(int i=0;i<rows1;i++){
                    for(int j=0;j<cols1;j++){
                        cout<<setw(4)<<arr1[i][j]+arr2[i][j]<<" ";
                    }
                    cout<<endl;
                }
                break;
            }
            case '-':
            {   cout<<"\nSubtraction :"<<endl;
                for(int i=0;i<rows1;i++){
                    for(int j=0;j<cols1;j++){
                        cout<<setw(4)<<arr1[i][j]-arr2[i][j]<<" ";
                    }
                    cout<<endl;
                }
                break;
            }
        

        }
    }
    } 
    else if(op=='*'){
        if(cols1==rows2){
            int m=rows1,n=cols2,c=cols1;
            cout<<"Multiplication :"<<endl;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    float sum=0;
                    for(int k=0;k<c;k++){
                        sum+=arr1[i][k]*arr2[k][j];
                    }
                    cout<<setw(4)<<sum<<" ";
                }
                cout<<endl;
            }


        }

    }
    else {
        cout<<"\nTwo matrices are not compatible for given operation "<<endl;
    }
    cout<<"\nContinue?(Y/N):";
    cin>>con;
    }
    
    return 0;
}
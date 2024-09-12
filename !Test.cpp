#include<iostream>
#include<vector>
using namespace std;
bool issort(vector<int>x){
        for(int i=1;i<x.size();i++){
            if(x[i-1]>x[i]){
                return false;
            }
        }
        return true;
    }

int main(){

    vector<int>vec={1,2,3};
    cout<<issort(vec);

    return 0;
}
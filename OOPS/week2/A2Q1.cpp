#include <iostream>
#include <iomanip>
#include<string>
#include<ios>
using namespace std;

int main() {
    int n=2;
    cout<<"Enter table name :";
    string title;
    cin>>title;
    string name[n];
    float price[n];
    cout<<"Enter product name and price :";
    for(int i=0;i<n;i++){
        cin>>name[i]>>price[i];
    }
    cout<<setw(11)<<setfill('=')<<title<<setw(6)<<setfill('=')<<""<<endl;
    cout<<setiosflags(ios::left);
    cout<<setfill(' ');
    for(int i=0;i<n;i++){
        cout<<setw(10)<<name[i]<<setw(10)<<fixed<<setprecision(3)<<price[i]<<endl;
    }

    return 0;
}

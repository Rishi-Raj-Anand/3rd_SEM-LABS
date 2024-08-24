#include<iostream>
using namespace std;
void isLeapYear(int year){
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
        cout<<"Leap Year";
    }else{
        cout<<"Not a Leap Year";
    }


}
int main(){
    int year;
    cout<<"Enter year :";
    cin>>year;
    isLeapYear(year);
    return 0;
}


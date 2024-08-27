#include<iostream>
using namespace std;
struct student{
    int ID;
    float GPA;
};

int main(){
    student s1;
    s1.ID=12435;
    s1.GPA=9.21;
    student * x;
    x=&s1;
    cout<<"ID :"<<x->ID<<"\nGPA :"<<x->GPA;
    return 0;
}


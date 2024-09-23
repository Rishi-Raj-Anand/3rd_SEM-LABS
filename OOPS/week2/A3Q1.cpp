#include<iostream>
#include<string>
using namespace std;
class student{
    private:
    string name;
    static int rollC;
    int roll;
    float cg;
    public:
    student(string n,float c):name(n),cg(c){
        roll=++rollC;
    }
    student(){
        roll=++rollC;
    }
    void setdetail(){
        cout<<"Enter student name :";
        cin>>name;
        cout<<"Enter student CGPA :";
        cin>>cg;
        cout<<"\n";
    }
    void getdetail(){
        cout<<"Name :"<<name<<endl;
        cout<<"Roll No. :"<<roll<<endl;
        cout<<"CGPA :"<<cg<<endl;
        cout<<"\n";
    }

};
int student::rollC=23103100;

int main(){
    student s1("Rishi",8.56);
    student s2;
    s1.getdetail();
    s2.setdetail();
    s2.getdetail();
    return 0;
}
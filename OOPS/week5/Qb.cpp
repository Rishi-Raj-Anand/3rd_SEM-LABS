#include<iostream>
#include<string>
using namespace std;

class Base{
    protected:
    string name;
    int Id;
    public:
    Base(string s,int id):name(s),Id(id){};
    Base():name("XXXXXX"),Id(0){}

    void show_name(){
        cout<<"Name :"<<name<<endl;
    }

    void show_ID(){
        cout<<"ID :"<<Id<<endl;
    }

    void write_name(string s){
        name=s;
    }

    void write_ID(int n){
        Id=n;
    }


};

class Teacher  :protected Base{
    private:
    int Class;
    string sub;
    public:
    Teacher(string n,int i,int c,string s):Base(n,i),Class(c),sub(s){}
    Teacher


};
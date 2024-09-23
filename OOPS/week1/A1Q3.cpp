#include <iostream>
#include<string>
using namespace std;
struct Student {
    string name;
    int age;
    float gpa;
};

void printStudent(Student student) {
    cout << "Name: " << student.name << endl;
    cout << "Age: " << student.age << endl;
    cout << "GPA: " << student.gpa << endl;
}

int main() {
    Student student;
    cout<<"Enter name of student :";
    getline(cin,student.name);
    cout<<"Enter age of student :";
    cin>>student.age;
    cout<<"Enter gpa of student :";
    cin>>student.gpa;

    printStudent(student);

    return 0;
}
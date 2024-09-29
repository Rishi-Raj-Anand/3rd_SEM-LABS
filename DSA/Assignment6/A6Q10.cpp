#include<iostream>
#include<string>
using namespace std;

struct student{
    string name;
    int age;
    float score;
    student(string a,int b,float c):name(a),age(b),score(c){}
};

struct node{
    student s;
    node*next;
    node(student a,node*n):s(a),next(n){}
    node(student n):s(n),next(NULL){}
};
void printStu(node*&h){
    node*temp=h;
    while(temp!=NULL){
        cout<<"Name :"<<temp->s.name<<endl;
        cout<<"Age :"<<temp->s.age<<endl;
        cout<<"Score :"<<temp->s.score<<endl;
        temp=temp->next;
        cout<<"\n"<<endl;
    }
}

int main(){
    student s1("Rishi",19,99),s2("Ram",20,89),s3("Rodeus",25,95);
    node n3(s3),n2(s2,&n3),n1(s1,&n2);
    node*Head=&n1;
    printStu(Head);

    return 0;
}
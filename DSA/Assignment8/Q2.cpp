#include<iostream>
#include<list>
using namespace std;
class Stack{
    list<int>li;
    public:

    void push(int v){
        li.push_back(v);
    }

    void pop(){
        if(li.empty()){
            return;
        }
        li.pop_back();
    }

    int top(){
        if(li.empty()){
            return -1;
        }
        return li.back();
    }

    void display(){
        list<int>cp=li;
        while(!cp.empty()){
            cout<<cp.back()<<" ";
            cp.pop_back();
        }
        cout<<endl;
    }

};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.display();

    s.pop();
    s.display();

    cout<<s.top()<<endl;

}
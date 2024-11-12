#include<iostream>
#include<stack>
#include<string>
using namespace std;

void reverseString(string &s){
    stack<int>st;
    for(int i=0;i<s.size();i++){
        st.push(s[i]);
    }
    string temp="";
    while(!st.empty()){
        temp+=st.top();
        st.pop();
    }
    s=temp;
    return;
}

int main(){
    string name="Rishi";
    reverseString(name);
    cout<<name<<endl;

    return 0;
}
#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool validParentheses(string &s){
    stack<char>ck;
    for(int i=0;i<s.size();i++){
        char x=s[i];
        if(x=='('||x=='{'||x=='['){
            ck.push(x);
        }else if(x==')'||x=='}'||x==']'){
            if(ck.empty()){
                return false;
            }
            else if((x==')'&&ck.top()=='(')||(x==']'&&ck.top()=='[')||(x=='}'&&ck.top()=='{')){
                ck.pop();
            }else{
                return false;
            }
        }
    }
    return ck.empty();
}

int main(){
    string test="[{()}]";
    cout<<validParentheses(test);

    return 0;
}
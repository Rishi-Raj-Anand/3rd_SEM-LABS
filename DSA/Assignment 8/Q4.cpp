#include<iostream>
#include<string>
#include<stack>
using namespace std;

int  postfixEval(string exp){
    stack<int>nums;
    for(int i=0;i<exp.size();i++){
        char temp=exp[i];
        if(temp=='+'||temp=='-'||temp=='*'||temp=='/'){
            int y=nums.top();
            nums.pop();
            int x=nums.top();
            nums.pop();
            switch (temp)
            {
            case '+':
                nums.push(x+y);
                break;
            case '-':
                nums.push(x-y);
                break;
            case '*':
                nums.push(x*y);
                break;
            case '/':
                nums.push(x/y);
                break;
            }
        }else{
            int val=temp-'0';
            nums.push(val);
        }
    }
    return nums.top();
}

int main(){
    string s="62+5*84/-";
    cout<<postfixEval(s);

    return 0;
}

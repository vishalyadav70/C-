#include<iostream>
#include<stack>
#include<math.h>
using namespace std;
int prec(char a){
    if(a=='^')
        return 3;
    else if(a=='*' || a=='/')
        return 2;
    else if(a=='+' || a=='-')
        return 1;
    else
        return -1;
}
string infixtopostfix(string str){
    stack<char>s;
    string result;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]>='a' && str[i]<='z' || str[i]>='A' && str[i]<='Z')
            result+=str[i];
        else if(str[i]=='(')
            s.push(str[i]);
        else if(str[i]=='('){
            while(!s.empty() && s.top()!='('){
                result+=s.top();
                s.pop();
            }
            if(!s.empty()){
                s.pop();
                }
        }
        else{
            while(!s.empty() && prec(s.top())>prec(str[i])){
                result+=s.top();
                s.pop();
            }
            s.push(str[i]);
        }
    }
    while(!s.empty()){
        result+=s.top();
        s.pop();
    }
    return result;
}

int main(){
    // string s=;
    cout<<infixtopostfix("(a-b/c)*(a/k-l)")<<endl;
    return 0;
}

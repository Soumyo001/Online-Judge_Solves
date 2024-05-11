#include<bits/stdc++.h>
using namespace std;
string infixToPostfix(string s){
    stack<char>st;
    string res="";
    auto ct=[&](char c)->int{
        if(c=='^') return 3;
         else if(c=='*' || c=='/') return 2;
         else if(c=='+' || c=='-') return 1;
         else return -1;
    };
    for(int i=0;i<s.length();i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
            res+=s[i];
        }
        else if(s[i]=='(') {
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                res+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty() && ct(st.top())>=ct(s[i])){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    return res;
}
int postfixEvaluation(string s){
    stack<int>st;
    for(int i=0;i<s.length();i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
            st.push(s[i]-'0');
        }else{
            int op2=st.top();st.pop();
            int op1=st.top();st.pop();
            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            case '^':
                st.push(pow(op1,op2));
            default:
                break;
            }
        }
    }
    return st.top();
}
int main(void){
    string s;cin>>s;
    cout<<infixToPostfix(s)<<endl;
    cout<<postfixEvaluation(infixToPostfix(s))<<endl;
}
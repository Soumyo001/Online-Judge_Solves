#include<bits/stdc++.h>
using namespace std;
string infixtopostfix(string& s){
    auto ct=[&](char s){
        if(s=='^') return 3;
        else if(s=='*' || s=='/') return 2;
        else if(s=='+' || s=='-') return 1;
        return -1;
    };
    string res="";
    stack<char>st;
    for(int i=0;i<s.length();i++){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) res+=s[i];
        else if(s[i]=='(') st.push(s[i]);
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                res+=st.top();st.pop();
            }
            if(!st.empty()) st.pop();
        }else{
            while(!st.empty() && ct(st.top())>=ct(s[i])){
                res+=st.top();st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        res+=st.top();st.pop();
    }
    return res;
}
int postfixEvaluation(string s){
    stack<int> st;
    for(int i=0;i<s.length();i++){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) st.push(s[i]-'0');
        else{
            int op1=st.top();st.pop();
            int op2=st.top();st.pop();
            if(s[i]=='+') st.push(op2+op1);
            else if(s[i]=='-') st.push(op2-op1);
            else if(s[i]=='*') st.push(op2*op1);
            else if(s[i]=='/') st.push(op2/op1);
            else if(s[i]=='^') st.push(pow(op2,op1));
        }
    }
    return st.top();
}
int main(void){
    string s;cin>>s;
    cout<<infixtopostfix(s)<<endl<<postfixEvaluation(infixtopostfix(s));
}
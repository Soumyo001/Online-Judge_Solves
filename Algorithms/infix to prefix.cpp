#include<bits/stdc++.h>
using namespace std;
void rev(int e,string& s){
    string res=s;
    for(int i=e-1,r=0;i>=0;i--,r++){
        if(res[i]==')'){
            s[r]='(';
        }
        else if(res[i]=='('){
            s[r]=')';
        }
        else if((res[i]>='a' && res[i]<='z') || (res[i]>='A' && res[i]<='Z') || (res[i]>='0' && res[i]<='9')){
            s[r]=res[i];
        }
        else{
            s[r]=res[i];
        }
    }
}
int ct(char s)
{
    if(s=='+' || s=='-')
        return 1;
    else if(s=='*' || s=='/')
        return 2;
    else if(s=='^')
        return 3;
    else
        return 0;
}
string infixToPostfix(string s){
    stack<char>st;
    string res="";
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
    rev(res.length(),res);
    return res;
}
int main(void){
    string s;
    cin>>s;
    rev(s.length(),s);
    cout<<s<<endl;
    cout<<infixToPostfix(s)<<endl;
}
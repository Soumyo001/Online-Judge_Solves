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
    rev(res.length(),res);
    return res;
}
int main(void){
    string s;
    cin>>s;
    rev(s.length(),s);
    cout<<infixToPostfix(s)<<endl;
}
#include<bits/stdc++.h>
using namespace std;
void reverseS(string& s){
    string r=s;
    for(int i=s.length()-1,j=0;i>=0;i--,j++){
        if(r[i]==')') s[j]='(';
        else if(r[i]=='(') s[j]=')';
        else s[j]=r[i];
    }
}
string infixtoprefix(string s){
    auto ct=[&](char c){
        if(c=='^') return 3;
        else if(c=='*' || c=='/') return 2;
        else if(c=='+' || c=='-') return 1;
        return -1;
    };
    stack<char>st;
    string res="";
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
    reverseS(res);
    return res;
}
int main(void){
    string s;cin>>s;
    reverseS(s);
    cout<<infixtoprefix(s)<<endl;
}
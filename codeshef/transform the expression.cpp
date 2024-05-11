#include<bits/stdc++.h>
using namespace std;
string infixToPostfix(string& s){
    auto it=[&](char c)->int{
        if(c=='^') return 3;
        else if(c=='*' || c=='/') return 2;
        else if(c=='+' || c=='-') return 1;
        return -1;
    };
    string res="";
    stack<char>st;
    for(auto i:s){
        if((i>='a' && i<='z') || (i>='A' && i<='Z') || (i>='0' && i<='9')) res+=i;
        else if(i=='(') st.push(i);
        else if(i==')'){
            while(!st.empty() && st.top()!='('){
                res+=st.top();st.pop();
            }
            if(!st.empty()) st.pop();
        }else{
            while(!st.empty() && it(st.top())>it(i)){
                res+=st.top();st.pop();
            }
            st.push(i);
        }
    }
    while(!st.empty()){
        res+=st.top();st.pop();
    }
    return res;
}
int main(void){
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        cout<<infixToPostfix(s)<<endl;
    }
}
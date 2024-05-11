#include<bits/stdc++.h>
using namespace std;
unordered_map<char,int>m={{'[',-3},{'{',-2},{'(',-1},{')',1},{'}',2},{']',3}};
string isBalanced(string s){
    stack<char>st;
    int n=0;
    for(auto c:s){
        if(m[c]<0){
            st.push(c);n++;
        }else{
            if(st.empty()) return "NO";
            char top=st.top();
            st.pop();
            if(m[c]+m[top]!=0) return "NO";
        }
    }
    if(n==s.length()) return "NO";
    if(st.empty()) return "YES";
    return "NO";
}
int main(void){
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        cout<<isBalanced(s)<<endl;
    }
}
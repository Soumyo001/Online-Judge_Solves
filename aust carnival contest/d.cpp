#include<bits/stdc++.h>
using namespace std;
string mul(string& s){
    string t;
    long long carry=0;
    for(int i=s.length()-1;i>=0;i--){
        long long mul=(s[i]-'0')*2+carry;
        carry=mul/10;
        t+=(mul%10+'0');
    }
    if(carry) t+=carry+'0';
    reverse(t.begin(),t.end());
    return t;
}
void solve(){
    string s;cin>>s;
    string t=mul(s);
    for(int i=0;i<30;i++){
        t=mul(t);
    }
    long long zero=0;
    for(int i=t.length()-1;i>=0;i--){
        if(t[i]!='0') break;zero++;
    }
    cout<<zero<<endl;
}
int main(void){
    int t;cin>>t;
    while(t--) solve();
}
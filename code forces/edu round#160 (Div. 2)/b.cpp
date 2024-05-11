#include<bits/stdc++.h>
using namespace std;
void solve(){
    string s;cin>>s;
    if(s.length()==1 || s.length()==3){
        cout<<1<<endl;return;
    }
    if(s.length()==2){
        cout<<0<<endl;return;
    }
    int o=0,z=0;
    for(int i=0;i<s.length();i++) {if(s[i]=='1') ++o; else if(s[i]=='0') ++z;}
    if(o==z){
        cout<<0<<endl;return;
    }
    int cost=0;
    for(int i=1;i<s.length();i++){
        if(s[i]==s[i-1]) {cost++;s[i]='#';}
    }
    cout<<cost+1<<endl;
}
int main(void){
    int t;cin>>t;
    while(t--) solve();
}

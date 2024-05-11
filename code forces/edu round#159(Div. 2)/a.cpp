#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    vector<int> zero,one;
    int o=0,z=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='0') ++z;
        else if(s[i]=='1') ++o;
    }
    if(z==s.length() || z>o){
        cout<<"YES"<<endl;return;
    }
    if(o==s.length()){
        cout<<"NO"<<endl;return;
    }
    for(int i=0;i<s.length()-1;i++){
        if((s[i]=='0' && s[i+1]=='0') || (s[i]=='1' && s[i+1]=='1')) one.push_back(1);
        else if((s[i]=='0' && s[i+1]=='1') || (s[i]=='1' && s[i+1]=='0')) zero.push_back(0);
    }
    if(one.size()+o<zero.size()+z) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main(void){
    int t;cin>>t;
    while(t--) solve();
}
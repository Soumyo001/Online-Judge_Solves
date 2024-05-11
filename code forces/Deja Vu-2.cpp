#include<bits/stdc++.h>
using namespace std;
void solve(){
    string s;cin>>s;
    string ans1="",ans2="";
    ans1=s+"a";
    ans2="a"+s;
    string temp=ans1;
    reverse(ans1.begin(),ans1.end());
    if(ans1 != temp){
        cout<<"YES"<<endl;
        cout<<temp<<endl;
        return;
    }temp=ans2;reverse(ans2.begin(),ans2.end());
    if(ans2!=temp){
        cout<<"YES"<<endl;
        cout<<temp<<endl;
        return;
    } 
    cout<<"NO"<<endl;
}
int main(void){
    int t;cin>>t;
    while(t--) solve();
}
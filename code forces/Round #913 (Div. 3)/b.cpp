#include<bits/stdc++.h>
#define debug2(x) cout<<x<<endl
#define debug() cout<<"Here"<<endl
using namespace std;
void solve(){
    string s="";cin>>s;
    if(s=="" || s.length()==1){
        if(s=="b" || s=="B"){
            s="";
            cout<<s<<endl;return;
        }
        cout<<s<<endl;return;
    }
    int all=1;
    for(int i=0;i<s.length();i++){
        if(s[i]!='b' || s[i]!='B') all=0;
    }
    if(all){
        s="";
        cout<<s<<endl;return;
    }
    string ans="";
    int l=0,r=0;
    for(int i=s.length()-1;i>=0;--i){
        if(s[i]=='b') r++;
        else if(s[i]=='B') l++;
        else{
            if(isupper(s[i])&&l) --l;
            else if(islower(s[i])&&r) --r;
            else ans+=s[i];
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}
int main(void){
    int t;cin>>t;
    while(t--) solve();
}
//prob name : YetnotherrokenKeoard
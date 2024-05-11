#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    int m=0,f=0;
    //for(int i=0;i<s.length();i++) if(s[i]=='0') ++m; else ++f;
    int ans=0,count=0;m=f=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            ++count;++m;
        }
        else if(s[i]=='1' && m==1) ++f;
        if(count==2){
            if(m>f) ans+=(2*m-2)-f;
            count=1;m=1;f=0;
        }
    }
    cout<<ans<<endl;
}
int main(void){
    int t;cin>>t;
    while(t--) solve();
}
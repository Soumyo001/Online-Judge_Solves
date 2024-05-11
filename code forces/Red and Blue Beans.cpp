#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long r,b,d;cin>>r>>b>>d;
    if((r==1 && b==1) || r==b){
        cout<<"YES\n";return;
    }
    if((r==1 && b>1) || (r>1 && b==1)){
        if(abs(b-r)<=d){
            cout<<"YES\n";return;
        }else{
            cout<<"NO\n";return;
        }
    }
    if(r!=b && d==0){
        cout<<"NO\n";return;
    }
    if(b<r) swap(r,b);
    if(b>(r*(d+1)*1LL)) cout<<"NO\n";
    else cout<<"YES\n";
}
int main(void){
    int t;cin>>t;
    while(t--) solve();
}
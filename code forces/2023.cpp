#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;cin>>n>>k;
    vector<int> v(n);
    long long m=1,ans=1;
    for(int i=0;i<n;i++){
        cin>>v[i];
        m*=v[i];
        if(2023%v[i]!=0) ans=0;
    }
    if(!ans){
        cout<<"NO"<<endl;return;
    }
    if(m==2023){
        cout<<"YES\n";
        for(int i=0;i<k;i++) cout<<1<<" ";cout<<endl;
        return;
    }else if(2023%m!=0 || m>2023){
        cout<<"NO\n";return;
    }
    cout<<"YES\n";
    int x=2023;x/=m;
    while(k-1){
        cout<<1<<" ";
        --k;
    }
    cout<<2023/m<<endl;
}
int main(void){
    int t;cin>>t;
    while(t--) solve();
}
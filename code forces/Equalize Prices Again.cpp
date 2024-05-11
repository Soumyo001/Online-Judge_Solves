#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    vector<int> v(n,0);
    long long sum=0;
    int same=1;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(i>0 && v[i]!=v[i-1]) same=0;
        sum+=(v[i]*1LL);
    }
    if(same){cout<<v[0]<<endl;return;}
    int ans=0;
    for(int i=1;;i++){
        if(i*n*1LL >= sum){
            ans=i;break;
        }
    }
    cout<<ans<<endl;
}
int main(void){
    int t;cin>>t;
    while(t--) solve();
}
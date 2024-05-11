#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(void){
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        int n;cin>>n;
        ll ans=INT_MIN;
        pair<ll,ll>p[n];
        for(int i=0;i<n;i++){
            int x,y,k;cin>>x>>y;
            p[i]=make_pair(x,y);
        }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                ll k=pow(p[i].first-p[j].first,2)+pow(p[i].second-p[j].second,2);
                ans=max(ans,k);
            }
        }
        cout<<"Case "<<i<<": "<<ans<<endl;
    }
}
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
const long long N=1e7+10;
long long q[N];
signed main(void){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n,a,b,c,m;cin>>n>>a>>b>>c>>m;
        int x=b,ans=0,r=0;
        for(int i=1;i<=n;i++){
            long long mx=INT_MIN,mn=INT_MAX;
            x=((a*(long long)x)+c)%m;
            if(x & 1){
               r++;q[r]=x;
               for(int i=1;i<=r;i++){
                mx=max(mx,q[i]);
                mn=min(mn,q[i]);
               }
            }else{
               if(r) {
               r--;
               for(int i=1;i<=r;i++){
                mx=max(mx,q[i]);
                mn=min(mn,q[i]);
               }
               }
            }
            if(r) ans^=(mx+mn);
        }
        cout<<ans<<endl;
    }
}
/*
3
450
23 67 23 900
23664
345 5767
21 9000
2340000
345
667
89909
99076
*/
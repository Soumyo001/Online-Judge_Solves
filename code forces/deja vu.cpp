#include<iostream>
#include<vector>
#include<algorithm>
#include<stdint.h>
#include<map>
#include<set>
#include<array>
#include<functional>
#include<cmath>
#include<chanmgr.h>
#include<bits/atomic_lockfree_defines.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/detail/standard_policies.hpp>
#define ll long long
using namespace std;
void solve(){
    int n,q;cin>>n>>q;
    vector<ll> a(n,0);
    vector<int> x(q,0);
    ll mx=LLONG_MIN;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    for(int i=0;i<q;i++) cin>>x[i];
    sort(x.begin(),x.end());
    sort(a.begin(),a.end());
    int i=q-1;
    for(int i=0;i<q;i++){
        for (int j = 1; j <= 30; j++)
        {
            //if() a[i]+=pow(2,j-1);
        }
    }
    for(auto i:a) cout<<i<<" ";
    cout<<endl;
}
int main(void){
    int t;cin>>t;
    while(t--) solve();
}
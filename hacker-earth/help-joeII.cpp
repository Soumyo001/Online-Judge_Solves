#include<bits/stdc++.h>
#define ll long long
using namespace std;
multiset<ll>ma;
int main(void){
    int n,m;cin>>n>>m;
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]%=m;
    }
    ll q;cin>>q;
    while(q--){
        int x;cin>>x;x%=m;
        ll* ptr=upper_bound(a+0,a+n,m-x-1);
        if(ptr!=a) --ptr;
        cout<<max((a[n-1]+x)%m,(*ptr+x)%m)<<endl;
    }
}
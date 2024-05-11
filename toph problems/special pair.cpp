#include<bits/stdc++.h>
using namespace std;
#define max 10005
#define ll long long
ll b[max][max];
int main(void){
    ll t;cin>>t;
    for(int i=1;i<=t;i++){
        ll n,q;cin>>n>>q;
        ll a[n+10];
        for (int i = 0; i < n; i++) cin>>a[i];
        for(int i=0;i<n;i++){
            b[i][i]=0;
            for(int j=i+1;j<n;j++){
                b[i][j]=b[i][j-1];
                if(a[i]%a[j]==0 && a[i]>a[j]) b[i][j]++;
            }
        }
        cout<<"Case "<<i<<":"<<endl;
        while(q--){
            ll l,r,ans=0;cin>>l>>r;
            l--;r--;
            for(int i=l;i<r;i++) ans+=b[i][r];
            cout<<ans<<endl;
        }
    }
}
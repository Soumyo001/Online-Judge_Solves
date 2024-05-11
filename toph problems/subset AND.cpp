#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int solve(){
    int n, k;
    cin >> n >> k;
    long long a[n + 10];
    long long t=(1LL<<40)-1;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) t&=a[i];
    cout<<(t<k?"YES":"NO")<<endl;
    return 0;
}
int main(void){
    fast;
    int t;cin>>t;
    while(t--) solve();
}
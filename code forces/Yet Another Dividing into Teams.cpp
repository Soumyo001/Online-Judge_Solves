#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) {cin>>v[i];}
    int t=1;
    for(int i=1;i<=n-1;i++) {for(int j=i+1;j<=n;j++) if(abs(v[j]-v[i])<=1){t=0;break;}if(!t) break;} 
    if(t) cout<<1<<endl;
    else cout<<2<<endl;

}
int main(void){
    int t;cin>>t;
    while(t--) solve();
}
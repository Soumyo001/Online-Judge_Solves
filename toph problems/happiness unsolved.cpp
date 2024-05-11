#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,m;cin>>n>>m;
    multiset<pair<int,int>>s;
    for(int i=1;i<=n;i++){
        int a,b;cin>>a>>b;
        s.insert({-1*b,a});
    }
    int totalhp=0,totalcost=0,ans=INT_MIN;
    for(auto& mm:s){
        int hp=-1*mm.first;
        int cost=mm.second;
        totalhp+=hp;
        totalcost+=cost;
        if(totalcost>m){
            totalcost-=cost;
            totalhp-=hp;
        }
        ans=max(ans,totalhp);
    }
    cout<<ans<<endl;
}
int main(void){
    int t;cin>>t;
    while (t--)
    {
        solve();
    }
    
}
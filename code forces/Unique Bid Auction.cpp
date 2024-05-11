#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    map<int,int> m;
    int same=1;
    vector<int> v(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        m[v[i]]++;
        if(i>1 && v[i]!=v[i-1]) same=0;
    }if(n==1){
        cout<<1<<endl;return;
    }if(same){
        cout<<-1<<endl;return;
    }
    int mini=INT_MAX,ans=-1;
    for(int i=1;i<=n;i++){
        if(m[v[i]]==1 && mini>v[i]){
            mini=v[i];
            ans=i;
        }
    }
    cout<<ans<<endl;
}
int main(void){
    int t;cin>>t;
    while(t--) solve();
}
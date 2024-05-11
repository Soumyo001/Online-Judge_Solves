#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    int all1=1;
    vector<int> v(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        if(v[i]==2) all1=0;
    }
    if(all1){
        cout<<1<<endl;return;
    }
    int ans=0;int a=0;int idx=-1;
    for(int i=1;i<=(n-1);i++){
        if(v[i]==2) ans++;
        for(int j=i+1;j<=n;j++) if(v[j]==2) a++;
        if(ans==a){
            idx=i;break;
        }a=0;
    }
    cout<<(idx==-1 ? -1:idx);cout<<endl;
}
int main(void){
    int t;cin>>t;
    while(t--) solve();
}
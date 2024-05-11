#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    vector<int> v(n,0);
    vector<int> b(n,0);
    int x=0;
    for(int i=0;i<n;i++) cin>>v[i],x^=v[i];
    int ans=0;
    for(int i=0;i<n;i++){
        b[i]=x^v[i];
        ans^=b[i];
    }
    if(0==ans)cout<<x<<endl;
    else cout<<-1<<endl;
}
int main(void){
    int t;cin>>t;
    while(t--) solve();
}
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    vector<int>v(n,0);
    int sorted=1;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(i>0 && v[i]!=v[i-1]) sorted=0;
    }
    if(n==1){
        cout<<n<<endl;return;
    }
    if(sorted){
        for(auto i:v) cout<<i<<" ";
        cout<<endl;return;
    }
    int lw=0,hi=0;
    for(int i=0;i<n;i++){
        if((i+1)!=v[i]){
            lw=i;int j=i;
            while(v[j]!=(i+1)) j++;
            hi=j;break;
        }
    }
    reverse(v.begin()+lw,v.begin()+hi+1);
    for(auto i:v) cout<<i<<" ";
    cout<<endl;
}
int main(void){
    int t;cin>>t;
    while(t--) solve();
}
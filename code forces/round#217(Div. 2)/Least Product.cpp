#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    vector<int> v(n,0);
    long long pro=1;
    int negN=0;
    bool zero=false;
    int min=INT_MAX;
    for(int i=0;i<n;i++){
        cin>>v[i];pro*=v[i];
        if(v[i]<0) ++negN;
        if(v[i]==0) zero=true;
        if(min>v[i]) min=v[i];
    }
    if(zero || negN%2){
        cout<<0<<endl;
    }else{
        cout<<1<<endl<<1<<" "<<0<<endl;
    }
}
int main(void){
    int t;cin>>t;
    while(t--) solve();
}
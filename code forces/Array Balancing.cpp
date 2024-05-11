#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
void solve(){
    int n;cin>>n;
    vector<long long> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=1;i<n;i++){
        if((abs(a[i]-a[i-1])+abs(b[i]-b[i-1]))>(abs(b[i]-a[i-1])+abs(a[i]-b[i-1]))) swap(a[i],b[i]);
    }
    // for(auto i:a) cout<<i<<" ";cout<<endl;
    // for(auto i:b) cout<<i<<" ";cout<<endl;
    long long sum=0;
    for(int i=1;i<n;i++){
        sum+=abs(a[i]-a[i-1]);
        sum+=abs(b[i]-b[i-1]);
    }
    cout<<sum<<endl;
}
int main(void){
    int t;cin>>t;
    while(t--) solve();
}
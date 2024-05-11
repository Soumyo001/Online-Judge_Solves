#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long sum=0;
    int op=0,zeros=0;
    int n;cin>>n;
    bool is=true;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        if(x==0) {zeros++;continue;}
        a[i]=x;
        sum+=abs(a[i]);
        if(x<0 && is) op++,is=false;
        if(x>0) is=true;
    }
    cout<<sum<<" "<<op<<endl;
}
int main(void){
    int t;cin>>t;
    while(t--) solve();
}
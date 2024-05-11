#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long n;cin>>n;
    long long num=205;
    long long ans=0;
    if(n%2050!=0){
        cout<<-1<<endl;
        return;
    }
    n/=2050;
    while (n)
    {
        ans+=n%10;
        n/=10;
    }
    cout<<ans<<endl;
    
}
int main(void){
    int t;cin>>t;
    while(t--) solve();
}
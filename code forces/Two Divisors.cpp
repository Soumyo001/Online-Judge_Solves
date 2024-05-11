#include<bits/stdc++.h>
using namespace std;
void solve(){
    int a,b;cin>>a>>b;
    if(b%a==0) cout<<b*(b/a)<<endl;
    else  cout<<b*(a/__gcd(a,b))<<endl;
}
int main(void){
    int t;cin>>t;
    while(t--) solve();
}
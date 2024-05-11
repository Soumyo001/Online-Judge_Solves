#include<bits/stdc++.h>
using namespace std;
void solve(){
    int a,b;cin>>a>>b;
    if(a==b) cout<<"Bob\n";
    else if((a&1 && !(b&1))||(!(a&1 )&& b&1)) cout<<"Alice\n";
    else if((a&1 && b&1) || (!(a&1) && !(b&1))) cout<<"Bob\n";
}
int main(void){
    int t;cin>>t;
    while(t--) solve();
}
//Wine Factory (Easy Version)

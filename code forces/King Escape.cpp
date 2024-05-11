#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n;
void solve(){
    int a1,a2,b1,b2,c1,c2;
    cin>>a1>>a2>>b1>>b2>>c1>>c2;
    if((a1>c1 && a2>b2 && a1>b1 && a2>c2) || (a2<b2 && a1>b1 && a2<c2 && a1>c1)
    || (a1<b1 && a2>b2 && a1<c1 && a2>c2) || (a1<b1 && a2<b2 && a1<c1 && a2<c2)) cout<<"YES\n";
    else cout<<"NO\n";
}
int main(void){
    cin>>n;
    solve();
}
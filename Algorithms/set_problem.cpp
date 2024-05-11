#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        unordered_set<ll>s;
        while(n--){
            int x;cin>>x;
            s.insert(x);
        }
        while(m--){
            ll x;cin>>x;
            if(s.find(x)!=s.end()){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
                s.insert(x);
            }
        }
    }
}
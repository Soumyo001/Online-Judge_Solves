#include<bits/stdc++.h>
#define ctest(k) cout<<"Case "<<k<<": "<<endl;
using namespace std;
int32_t main(void){
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        int n,q;cin>>n>>q;
        vector<long long>v;
        for(int i=0;i<n;i++) {int j;cin>>j;v.emplace_back(j);}
        long long l,r;
        ctest(i);
        while(q--){
            cin>>l>>r;
            int mx=INT_MIN,cn=0;
            for(int i=l;i<=r;i++){
                if(mx<v[i]){
                    mx=v[i];
                    cn=0;
                }
                if(mx==v[i]) cn++;
            }
            cout<<cn<<endl;
        }
    }
}
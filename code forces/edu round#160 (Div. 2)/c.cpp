#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int q;
    cin >> q;
    vector<ll> m;
    while (q--){
        int t; ll v;
        cin >> t >> v;
        if (t == 1) m.push_back(pow(2, v));
        else {
            if(v==0){
                if(m.empty())cout<<"YES\n";
                else cout<<"NO\n";
                continue;
            }
            sort(m.begin(),m.end());
            int flag=0;
            int n = 1<<(m.size());
            for(int mask=0;mask<n;++mask){
                ll sum=0;
                for(int i=0;i<(int)m.size();i++){
                    if(mask & 1<<i){
                        sum+=m[i];
                    }
                }
                if(sum==v){
                    flag=1;break;
                }
            }
            if(flag) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}

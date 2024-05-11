#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    map<string,long long> m;
    m["00"]=INT_MAX,m["01"]=INT_MAX,m["10"]=INT_MAX,m["11"]=INT_MAX;
    for(int i=0;i<n;i++){
        long long x;string s;cin>>x>>s;
        m[s]=min(m[s],x);
    }
    if(min(m["11"],m["01"]+m["10"])!=INT_MAX) cout<<min(m["11"],m["01"]+m["10"])<<endl;
    else cout<<-1<<endl;
}
int main(void)
{
    int t;
    cin >> t;
    while (t--)
        solve();
}
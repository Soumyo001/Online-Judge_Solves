#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+6;
struct QUERY{
    int val;int idx;
    QUERY(int val,int idx){
        this->val=val;
        this->idx=idx;
    }
};
vector<QUERY> query;
void solve(){
    int n,q;cin>>n>>q;
    query.clear();
    multiset<pair<int,int>> s;
    vector<int>ans(q,0);
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        s.insert(make_pair(a,b));
    }
    for(int i=0;i<q;i++){
        int x;cin>>x;
        query.push_back(QUERY(x,i));
    }
    sort(query.begin(),query.end(),[&](const QUERY& a,const QUERY&b){return a.val<b.val;});

}
int main(void){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case "<<i<<": \n";
        solve();
    }
}
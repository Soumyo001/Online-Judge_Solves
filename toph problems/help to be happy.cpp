#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int status[N],totVill=0;
vector<int>peeps;
vector<int>graph[N];
void inputGraph(int number_of_edges){
    for(int i=1;i<=number_of_edges;i++){
        int n,m;cin>>n>>m;
        graph[n].push_back(m);
        graph[m].push_back(n);
    }
}
void initiStatus(int number_of_nodes){
    for(int i=1;i<=number_of_nodes;i++) status[i]=1;
}
void dfs(int source,int number_of_nodes){
    stack<int> st;
    st.push(source);
    totVill++;status[source] = 2;
    while (!st.empty())
    {
        int val = st.top();
        st.pop();
        status[val] = 3;
        peeps.push_back(val);
        for (int i:graph[val])
        {
            if (status[i] == 1)
            {
                st.push(i);
                status[i] = 2;
            }
        }
    }
}
int main(void){
    int n,e;cin>>n>>e;
    vector<ll> a(n+1,0),b(n+1,0);
    vector<int> ans(n+1,0);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    inputGraph(e);
    initiStatus(n);
    int totHapVill=0;
    for(int i=1;i<=n;i++){
        if(status[i]!=3){
            dfs(i,n);
            ll h=0,s=0;
            for(auto& val:peeps){
                if(a[val]>b[val]) h+=(a[val]-b[val])/10;
                else s+=(b[val]-a[val]);
            }
            if(h>=s){
                totHapVill++;
                for(auto& it:peeps) ans[it]=1;
            }
            peeps.clear();
        }
    }
    cout<<totVill<<" "<<totHapVill<<" "<<totVill-totHapVill<<endl;
    for(int i=1;i<=n;i++) cout<<ans[i]<<((i!=n)? " ":"\n");
}
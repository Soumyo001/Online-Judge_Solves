#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int parent[N];
int v[N+5];
int idx[N];
void make(int i){
    parent[i]=i;
}
int find(int i){
    if(idx[v[i]]==0) return i;
    return i==parent[i]? i:parent[i]=find(parent[i]);
}
void Union(int i,int j){
    int x=find(idx[i]);
    int y=j;
    if(idx[j]!=0) y=find(idx[j]);
    if(x!=y) parent[x]=y;
   // cout<<x<<" "<<y<<endl;

}
int main(void){
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        int n,q;cin>>n>>q;
        memset(idx,0,sizeof(idx));
        for(int i=1;i<=n;i++) v[i]=parent[i]=0;
        for(int i=1;i<=n;i++) make(i);
        for(int i=1;i<=n;i++) {
			cin>>v[i];
            if(idx[v[i]]==0)idx[v[i]]=i;
            else parent[i]=idx[v[i]];
            //cout<<v[parent[i]]<<" ";
        }
        //cout<<endl;
        //for(int i=1;i<=10;i++) cout<<parent[i]<<" ";
        cout<<"Case "<<i<<":"<<endl;
        while(q--){
            int s;cin>>s;
            if(s==1)
            {
                int a, b;
                cin >> a >> b;
                Union(a,b);
            }
            else
            {
                int x;
                cin >> x;
                x=find(x);
                if(x>n) cout<<x<<endl;
                else cout<<v[x]<<endl;
            }
        }
        //for(int i:parent) cout<<i<<" ";
    }
}

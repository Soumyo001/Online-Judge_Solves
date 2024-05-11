#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
list<int>l[N];
int status[N],sze[N];
void inputGraph(int number_of_edges){
    for(int i=1;i<=number_of_edges;i++){
        int n,m;cin>>n>>m;
        l[n].push_back(m);
        l[m].push_back(n);
    }
}
void initiStatus(int number_of_nodes){
    for(int i=1;i<=number_of_nodes;i++) {
        sze[i]=0;
        //a[i]=0;
        status[i]=1;
    }
}
int bfs(int source,int number_0f_nodes,long long a[]){
    initiStatus(number_0f_nodes);
    queue<int>q;
    q.push(source);
    status[source]=2;
    while(!q.empty()){
        int val=q.front();q.pop();
        status[val]=3;
        while(!l[val].empty()){
            if(status[l[val].front()]==1){
                q.push(l[val].front());
                status[l[val].front()]=2;
            }
            sze[val]++;
            l[val].pop_front();
        }
    }
    int ct=0;
    for(int i=1;i<=number_0f_nodes;i++){
        if(sze[i]>=2 && a[i]) ct++;
    }
    return ct;
}
int main(void){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        long long a[n];
        inputGraph(n-1);
        for(int i=1;i<=n;i++) cin>>a[i];
        cout<<bfs(1,n,a)<<endl;
    }
}
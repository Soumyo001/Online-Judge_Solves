#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
vector<int> graph[N];
int arr[N],status[N];
vector<int> sources;
vector<vector<int>> v;
int n;
void inputGraph(){
    for(int i=1;i<=n;i++){
        status[i]=1;
        cin>>arr[i];
        if(arr[i]==-1){
            sources.push_back(i);
            continue;
        }
        graph[arr[i]].push_back(i);
        graph[i].push_back(arr[i]);
    }
}
int bfs(int source){
    queue<int> q;
    vector<int> s;
    q.push(source);
    status[source]=2;
    q.push(-1);
    int count=1;
    while(!q.empty()){
        int val=q.front();q.pop();
        status[val]=3;
        if(val!=-1){
            s.push_back(val);
            for(auto i:graph[val]){
                if(status[i]==1){
                    q.push(i);status[i]=2;
                }
            }
        }else if(!q.empty()){
            ++count;
            v.push_back(s);s.clear();
            q.push(-1);
        }
    }
    return count;
}
int main(void){
    cin>>n;
    inputGraph();
    int ans=INT_MIN;
    for(auto i:sources){
        ans=max(ans,bfs(i));
    }
    cout<<ans<<endl;
}
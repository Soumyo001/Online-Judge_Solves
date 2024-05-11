#include<bits/stdc++.h>
using namespace std;
const int N=510;
long long dist[N][N];
int main(void){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>dist[i][j];
        }
    }
    vector<int> del_order;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        del_order.push_back(a);
    }
    reverse(del_order.begin(),del_order.end());
    vector<long long> ans;
    for(int k=0;k<n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j],dist[i][del_order[k]]+dist[del_order[k]][j]);
            }
        }
        long long sum=0;
        for(int i=0;i<=k;i++){
            for(int j=0;j<=k;j++){
                sum+=dist[del_order[i]][del_order[j]];
            }
        }
        ans.push_back(sum);
    }
    reverse(ans.begin(),ans.end());
    for(auto& i:ans){
        cout<<i<<" ";
    }
}
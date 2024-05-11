#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int wt[N],value[N];
int dp[100][10005];
long long knapsack(int idx, int wt_left){
    if(wt_left == 0) return 0;
    if(idx < 0) return 0;
    if(dp[idx][wt_left] != -1) return dp[idx][wt_left];
    long long ans = knapsack(idx-1, wt_left);
    if(wt_left - wt[idx] >= 0) ans = max(ans,knapsack(idx-1, wt_left-wt[idx])+value[idx]);
    return dp[idx][wt_left] = ans;
}
int main(void){
    memset(dp,-1,sizeof(dp));
    int n,W;cin>>n>>W;
    for(int i=0;i<n;i++) cin>>wt[i]>>value[i];
    cout<<knapsack(n-1,W)<<endl;
}
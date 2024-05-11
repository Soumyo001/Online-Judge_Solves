#include<bits/stdc++.h>
using namespace std;
int wt[1005],val[1005];
long long dp[105][100005];
long long func(int idx,int wt_left){
    if(wt_left==0) return 0;
    if(idx<0) return 0;
    if(dp[idx][wt_left] != -1) return dp[idx][wt_left];
    //dont choose item at idx
    long long ans=func(idx-1,wt_left);
    //choose item at idx
    if(wt_left-wt[idx]>=0) ans=max(ans,func(idx-1,wt_left-wt[idx])+val[idx]);
    return dp[idx][wt_left]=ans;
}
int main(void){
    memset(dp,-1,sizeof(dp));
    int n,w;cin>>n>>w;
    for(int i=0;i<n;i++) cin>>wt[i]>>val[i];
    cout<<func(n-1,w)<<endl;
}
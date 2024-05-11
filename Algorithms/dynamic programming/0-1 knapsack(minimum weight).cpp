#include<bits/stdc++.h>
using namespace std;
int wt[1005],val[1005];
long long dp[105][100005];
long long func(int idx,int value_left){
    if(value_left==0) return 0;
    if(idx<0) return 1e15;
    if(dp[idx][value_left] != -1) return dp[idx][value_left];
    //dont choose item at idx
    long long ans=func(idx-1,value_left);
    //choose item at idx
    if(value_left-val[idx]>=0) ans=min(ans,func(idx-1,value_left-val[idx])+wt[idx]);
    return dp[idx][value_left]=ans;
}
int main(void){
    memset(dp,-1,sizeof(dp));
    int n,w;cin>>n>>w;
    for(int i=0;i<n;i++) cin>>wt[i]>>val[i];
    long long max=1e5;
    for(int i=max;i>=0;i--){
        if(func(n-1,i)<=w){
            cout<<i<<endl;
            break;
        }
    }
}
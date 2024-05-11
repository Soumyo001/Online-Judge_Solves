#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int value[N],wt[N];
int dp[1005][10005];
long long knapsack(int idx, int val_left){
    if(val_left == 0) return 0;
    if(idx < 0) return int(1e15);
    if(dp[idx][val_left] != -1) return dp[idx][val_left];
    long long ans = knapsack(idx-1, val_left);
    if(val_left - value[idx] >= 0) ans = min(ans,knapsack(idx-1, val_left-value[idx]) + wt[idx]);
    return dp[idx][val_left] = ans;
}
int main(void){
    memset(dp, -1 ,sizeof(dp));
    int n,W;cin>>n>>W;
    int temp;
    for(int i=0;i<n;i++) cin>>wt[i]>>value[i];
    for(int i = 1e3; i>=0; i--){
        if(knapsack(n-1, i) <= W){
            cout<<i<<endl;
            temp=i;
            break;
        }
    }
}
#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
struct Matrix{
    int row,col;
};
vector<Matrix> matrix;
int mcm(int i,int j){
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=numeric_limits<int>::max();
    for(int k=i;k<j;k++) ans=min(ans,mcm(i,k)+mcm(k+1,j)+matrix[i].row*matrix[k].col*matrix[j].col);
    return dp[i][j]=ans;
}
int main(void){
    memset(dp,-1,sizeof(dp));
    int n;cin>>n;
    int arr[n+1];
    for(int i=0;i<=n;i++) cin>>arr[i];
    matrix.resize(n+1);
    for(int i=0;i<n;i++){
        matrix[i].row=arr[i];
        matrix[i].col=arr[i+1];
    }
    cout<<mcm(0,n-1);
}
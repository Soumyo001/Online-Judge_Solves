#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int dp[1005][1005];
struct Matrix{
    int row,col;
    Matrix(int _row,int _col){
        row=_row;
        col=_col;
    }
};
vector<Matrix>matrix;
int mcm(int i,int j){
    if(i>=j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=INT_MAX;
    for(int k=i;k<j;k++){
        ans=min(ans,mcm(i,k)+mcm(k+1,j)+matrix[i].row*matrix[k].col*matrix[j].col);
    }
    return dp[i][j]=ans;
}
int main(void){
    memset(dp,-1,sizeof(dp));
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int d1,d2;cin>>d1>>d2;
        matrix.push_back(Matrix(d1,d2));
    }
    cout<<mcm(0,n-1)<<endl;
}
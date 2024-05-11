#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int lcs(int i,int j,string& s1,string& s2){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j]=max(max(lcs(i-1,j,s1,s2),lcs(i,j-1,s1,s2)),lcs(i-1,j-1,s1,s2)+(s1[i]==s2[j]));
}
int main(void){
    memset(dp,-1,sizeof(dp));
    string s,t;cin>>s>>t;
    cout<<lcs(s.length()-1,t.length()-1,s,t)<<endl;
}
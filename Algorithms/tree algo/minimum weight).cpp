#include<bits/stdc++.h>
using namespace std;
int wt[1005],val[1005];
long long dp[105][100005];
long long func(int idx,int value_left){
    if(value_left==0) return 0;
    if(idx<0) return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int value[N],wt[N];
multiset<pair<double,pair<int,int>>> m;
double fractional_knapsack(int w){
    double tot = 0;
    for(auto& i: m){
        if(i.second.first <= w){
            tot += i.second.second;
            w -= i.second.first;
        }else{
            tot += (-1* i.first * w);
            w=0;
        }
    }
    return tot;
}
int main(void){
    int n,W;cin>>n>>W;
    for(int i=0;i<n;i++){
        cin>>wt[i]>>value[i];
        m.insert({-1.0*(value[i]/wt[i]),{wt[i],value[i]}});
    }
    cout<<fractional_knapsack(W)<<endl;
}
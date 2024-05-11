#include<bits/stdc++.h>
using namespace std;
multiset<pair<double,pair<int,int>>> m;
double fractional_knapsack(int w){
    double ans=0;
    for(auto& i:m){
        double valPerWt=-1.0*i.first;
        int wt=i.second.first;
        int val=i.second.second;
        if(w>=wt){
            ans+=val;
            w-=wt;
            continue;
        }
        ans+=(w*valPerWt);
        w-=(wt-(wt-w)); // or u can simply put w=0
    }
    return ans;
}
int main(void){
    int n,w;cin>>n>>w;
    for(int i=0;i<n;i++){
        int wt,val;cin>>wt>>val;
        m.insert({-1.0*(val/wt),{wt,val}});
    }
    cout<<fractional_knapsack(w)<<endl;
}
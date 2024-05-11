#include<bits/stdc++.h>
using namespace std;
int n;
int main(void){
    int t;cin>>t;
    while(t--){
        cin>>n;
        vector<int> v(2*n,0);
        for (int i = 0; i < 2*n; i++) cin>>v[i];
        sort(v.begin(),v.end());
        vector<int>x;
        vector<int>y;
        pair<int,int>p[n];
        int sum=0;
        for(int i=0;i<n;i++)x.push_back(v[i]);
        for(int i=n;i<2*n;i++)y.push_back(v[i]);
        for(int i=1;i<x.size();i++)sum+=abs(x[i]-x[i-1]);
        for(int i=1;i<y.size();i++)sum+=abs(y[i]-y[i-1]);
        cout<<sum<<endl;
        for(int i=0;i<x.size();i++) p[i].first=x[i];
        for(int i=0;i<y.size();i++) p[i].second=y[i];
        for(auto& i:p) cout<<i.first<<" "<<i.second<<endl;
    }
}
#include<bits/stdc++.h>
using namespace std;
int main(void){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<int> h(n+1),p(n+1);
        multiset<pair<int,int>>h1;
        for(int i=1;i<=n;i++)cin>>h[i],h1.insert({h[i],i});
        for(int i=1;i<=n;i++)cin>>p[i];
        while(!h1.empty()){
            int mn=INT_MAX;
            for(auto i:h1) {if(i.first>0)i.first-=k;else h1.erase(h1.find({i.first,i.second}));}
            for(auto i:h1) mn=min(mn,p[i.second]);
            k-=mn;
        }
        if(h1.empty()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
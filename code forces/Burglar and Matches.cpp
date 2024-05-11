#include<bits/stdc++.h>
using namespace std;
int main(void){
    vector<pair<int,int>> m;
    int n,c;cin>>n>>c;
    int temp=n;
    for(int i=0;i<c;i++){
        int a,b;cin>>a>>b;m.push_back({a,b});
    }
    long long count=0;
    long long mx=LLONG_MIN;
    sort(m.begin(),m.end(),[](const pair<int,int>& a,const pair<int,int>& b){
        return a.second>b.second;
    });
    for(auto& i:m){
        if(i.first<n){
            count+=(i.first*i.second);
            n-=(i.first);
        }else{
            count+=(n*i.second);
            break;
        }
    }
    cout<<count<<endl;
}
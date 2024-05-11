#include<bits/stdc++.h>
using namespace std;
    vector<pair<int,int>> v;
int main(void){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int start,end;cin>>start>>end;
        v.push_back({start,end});
    }
    sort(v.begin(),v.end(),[&](const pair<int,int>& a,const pair<int,int>& b){
        return a.second<b.second;
    });
    int take=1;
    int end=v[0].second;
    cout<<v[0].first<<" "<<v[0].second<<endl;
    for(int i=1;i<n;i++){
        if(v[i].first>=end){
            take++;
            end=v[i].second;
            cout<<v[i].first<<" "<<v[i].second<<endl;
        }
    }
    cout<<take<<endl;
}
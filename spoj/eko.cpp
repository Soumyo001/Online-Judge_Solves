#include<bits/stdc++.h>
using namespace std;
vector<long long>v;
int n;long long m;
bool isMaxHeight(int val){
    long long woodamnt=0;
    for(int i=0;i<v.size();i++){
        if(v[i]>=val) woodamnt+=(v[i]-val);
    }
    return woodamnt>=m;
}
int main(void){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        long long m;cin>>m;
        v.push_back(m);
    }
    long long lo=1,hi=1e9;
    while(hi-lo>1){
        long long mid=(lo+hi)/2;
        if(isMaxHeight(mid)) lo=mid;
        else hi=mid-1;
    }
    if(isMaxHeight(hi)) cout<<hi<<endl;
    else cout<<lo<<endl;
}
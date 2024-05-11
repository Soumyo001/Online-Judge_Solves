#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<long long>v;
ll n;int c;
bool canAllocate(ll val){
    ll lastpos=-1;
    int ct=c;
    for(int i=0;i<v.size();i++){
        if((v[i]-lastpos>=val || lastpos==-1) && ct!=0) lastpos=v[i],ct--;
    }
    return ct==0;
}
int main(void){
    int t;cin>>t;
    while(t--){
        v.clear();
        cin>>n>>c;
        for(int i=0;i<n;i++){
            ll x;cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        ll lo=0,hi=(ll)1e9;
        while(hi-lo>1){
            ll mid=(lo+hi)/2;
            if(canAllocate(mid)) lo=mid;
            else hi=mid-1;
        }
        if(canAllocate(hi)) cout<<hi<<endl;
        else cout<<lo<<endl;
    }
}
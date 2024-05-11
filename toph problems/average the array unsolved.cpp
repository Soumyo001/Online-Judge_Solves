#include<bits/stdc++.h>
using namespace std;
vector<long long>v;
int n,q;
long long lo,hi;
double k;
bool isBelowAvg(long long mid){
    double sum=0;
    for(long long i=lo;i<=mid;i++){
        sum+=v[i];
    }
    sum/=((mid-lo)+1);
    return sum<k;
}
int main(void){
    cin>>n;
    for(int i=0;i<n;i++) {
        long long a;cin>>a;
        v.emplace_back(a);
    }
    sort(v.begin(),v.end());
    cin>>q;
    while(q--){
        cin>>k;
        lo=0,hi=v.size()-1; 
        while(hi-lo>1){
            long long mid=(lo+hi)/2;
            if (isBelowAvg(mid)) lo=mid;
            else hi=mid-1;
        }
        if(isBelowAvg(hi)) cout<<hi+1<<endl;
        else cout<<lo<<endl;
    }
}
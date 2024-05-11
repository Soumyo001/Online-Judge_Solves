#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    int n,x;cin>>n>>x;
    ll lo=1,hi=n,mid;
    ll c=0;
    while(hi-lo>=1){
        c++;
        mid=(lo+hi)/2;
        if(mid<x) lo=mid+1;
        else hi=mid;
    }
    cout<<c<<endl;
}
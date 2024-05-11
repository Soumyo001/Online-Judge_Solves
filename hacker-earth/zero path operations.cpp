#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(void){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int e=n-1;
        unordered_map<int,int>m;
        while(e--){
            int a,b;cin>>a>>b;
            m[a]++;
            m[b]++;
        }
        ll a[n+1];
        for(int i=1;i<=n;i++) cin>>a[i];
        int ct=0,;
        for(auto& it:m){
            if(it.second>=2 && a[it.first]) ct++;
        }
        cout<<ct<<endl;
    }
}
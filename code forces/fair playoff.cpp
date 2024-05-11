#include<bits/stdc++.h>
using namespace std;
int main(void){
    pair<int,int> a,b;
    int t;cin>>t;
    while(t--){
        cin>>a.first>>a.second>>b.first>>b.second;
        int maxa=max(a.first,a.second);
        int maxb=max(b.first,b.second);
        if(min(maxa,maxb)==a.first || min(maxa,maxb)==a.second){
            if(maxb==b.first && min(maxa,maxb)<b.second) cout<<"NO"<<endl;
            else if(maxb==b.second && min(maxa,maxb)<b.first) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }else if(min(maxa,maxb)==b.first || min(maxa,maxb)==b.second){
            if(maxa==a.first && min(maxa,maxb)<a.second) cout<<"NO"<<endl;
            else if(maxa==a.second && min(maxa,maxb)<a.first) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
}
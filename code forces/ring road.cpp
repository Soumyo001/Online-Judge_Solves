#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
int s[N],e[N];

int main(void){
    cin>>n;
    int cost=0,ans=0;
    int ct=0;
    for(int i=0;i<n;i++){
        int a,b,c;cin>>a>>b>>c;
        if(s[a] || e[b]) ct+=c,s[b]=e[a]=1;
        else s[a]=e[b]=1;
        ans+=c;
    }
    cout<<min(ct,ans-ct);
}
#include<bits/stdc++.h>
using namespace std;
int main(void){
    int t;cin>>t;
    while(t--){
        int n,k,p=-1,d;cin>>n>>k;
        string s,mx="";
        cin>>s;
        for(int i=0;i<n;i++){
            if(mx<s){
                mx=s;
                d=i;
            }else if(mx==s){
                p=i-d;break;
            }
            s=s.substr(1)+s.substr(0,1);
        }
        if(p==-1) cout<<1LL*(d+(k-1)*n)<<endl;
        else cout<<1LL*(d+(k-1)*p)<<endl;
    }
}
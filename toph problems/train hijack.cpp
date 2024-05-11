#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll maximum(ll a,ll b,ll c){
    if(a>b&&a>c) return a;
    else if(a>b&&c>a) return c;
    else if(b>a&&b>c) return b;
    else if(b>a&&c>b) return c;
    else if(c>a&&c>b) return c;
    else if(c>a&&b>c) return b;
}
ll minimum(ll a,ll b,ll c){
    if(a<b&&a<c) return a;
    else if(a<b&&c<a) return c;
    else if(b<a&&b<c) return b;
    else if(b<a&&c<b) return c;
    else if(c<a&&c<b) return c;
    else if(c<a&&b<c) return b;
}
int main(void){
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        int n;cin>>n;
        ll v[10001];
        for(int i=0;i<n;i++){
            int n;cin>>v[i];
        }
        long long int sum=v[0],maxi=v[0],mini=v[0];
        /*for(int i=1;i<n;i++){
            if(v[i]==0) {maxi=mini=1;continue;}
            int temp=maxi,temp1=mini;  
            /*maxi=maximum(v[i],v[i]*maxi,v[i]*mini);
            mini=minimum(v[i],v[i]*temp,v[i]*mini);
            sum=max(sum,maxi);*/            
            /*maxi=max(maxi*v[i],v[i]);
            if(maxi<mini*v[i]) maxi=max(mini*v[i],v[i]);
            mini=min(temp*v[i],v[i]);
            if(mini>temp1*v[i])mini=min(temp1*v[i],v[i]);
            sum=max(sum,maxi);
        }*/
        for(int i=0;i<n;i++){
            long long int mul=v[i];
            for(int j=i+1;j<n;j++){
                  sum=max(sum,mul);
                  mul*=v[j];
            }
            sum=max(sum,mul);
        }
        cout<<"Case "<<i<<": "<<sum<<endl;
    }
}

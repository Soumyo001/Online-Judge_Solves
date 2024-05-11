#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
int a[N],h[N];
int main(void){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        int l=1;h[1]=0;
        for(int i=2;i<=n;i++){
            if(a[i]<a[i-1]) l++;
            h[i]=h[l]+1;
        }
        cout<<h[n]<<endl;
    }
}
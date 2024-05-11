#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    vector<int> a(n),b(n);
    int mxa=INT_MIN,mxb=INT_MIN;
    int ai,bi;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        if(mxa<a[i]){
            mxa=a[i];
            ai=i;
        }
    }
    for(int i=0;i<n;i++) {
        cin>>b[i];
        if(mxb<b[i]){
            mxb=b[i];
            bi=i;
        }
    }
    if(ai==n-1 and bi==n-1){
        cout<<"Yes"<<endl;return;
    }
    bool yes=true;
    for(int i=0;i<n-1;i++){
        if(a[i]>a[n-1]) swap(a[i],b[i]); 
        if(b[i]>b[n-1]) swap(a[i],b[i]);
    }
    for(int i=0;i<n-1;i++){
        if(a[i]>a[n-1]) yes=false; 
        if(b[i]>b[n-1]) yes=false;
    }
    if(yes) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
int main(void){
    int t;cin>>t;
    while(t--) solve();
}
#include<bits/stdc++.h>
using namespace std;
int main(void){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> v(n,0);
        for(int i=0;i<n;i++) cin>>v[i];
        sort(v.begin(),v.end());
        int ans=INT_MAX;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++) ans=min(ans, abs(v[j]-v[i]));
        }
        cout<<ans<<endl;
    }
}
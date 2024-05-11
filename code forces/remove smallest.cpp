#include<bits/stdc++.h>
using namespace std;
int main(void){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int ct=0;
        vector<int> v(n,0);
        for(int i=0;i<n;i++){
            cin>>v[i];
            if(i>0 && v[i]==v[i-1]) ct++;
        }
        if(ct+1==n){
            cout<<"YES"<<endl;continue;
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(v[i]!=0 && v[j]!=0 && abs(v[j]-v[i])<=1){
                    if(v[i]<v[j]) v[i]=0;
                    else v[j]=0;
                }
            }
        }
        ct=0;
        for(int i=0;i<n;i++) if(v[i]) ct++;
        if(ct==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
#include<bits/stdc++.h>
using namespace std;
int main(void){
    int t;cin>>t;
    while(t--){
        vector<int>v(3,0);
        int n;cin>>v[0]>>v[1]>>v[2]>>n;
        sort(v.begin(),v.end());
        n-=(2*v[2]-v[1]-v[0]);
        if(n<0 || n%3!=0) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        
    }
}
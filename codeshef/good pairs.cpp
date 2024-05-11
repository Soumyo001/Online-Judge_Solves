#include<bits/stdc++.h>
using namespace std;
int main(void){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        unordered_map<int,int>m;
        long long sum=0;
        for(int i=0;i<n;i++){
            int a;cin>>a;
            m[a]++;
        }
        for(auto& it:m){
            sum+=(1LL*it.second*(it.second-1))/2;
        }
        cout<<sum<<endl;
    }
}
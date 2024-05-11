#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n,k;cin>>n>>k;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    int q=n/3;
    for(int i=1;i<=n;i++){
        if((5-v[i])<k && i%3==0)q--;
    }
    cout<<q;
}
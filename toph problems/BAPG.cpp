#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int>l;
int main(void){
    int t;cin>>t;
    while(t--){
        int sum=0;
        l.clear();
        int n,m;cin>>n>>m;
        while(m--){
            int x;cin>>x;l.push_back(x);
        }
        sort(l.begin(),l.end());
        while(n--) {
            sum+=l.back();l.pop_back();
        }
        cout<<sum<<endl;
    }
}
#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n,m;cin>>n>>m;
    vector<int> a(n,0);
    vector<int> b(m,0);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int j=0;j<m;j++) cin>>b[j];
    int s1,s2;
    cin>>s1>>s2;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    long long cnt=0;
    for(int i=0;i<n;i++){
       if(a[i]<=s2){
            for(int j=0;j<m;j++){
                if(b[j]<=s2) {if(a[i]+b[j]>=s1 && a[i]+b[j]<=s2) cnt++;}
                else break;
            }
       }
    }
    cout<<cnt;
}
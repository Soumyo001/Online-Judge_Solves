#include<bits/stdc++.h>
using namespace std;
int main(void){
    int ans=0;
    pair<int,int> p;
    int n;cin>>n;
    vector<string> v(n+2);
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        if(s[0]=='O' && s[1]=='O' && !ans){
            ans=i;
            p.first=0;p.second=1;
        }else if(s[3]=='O' && s[4]=='O' && !ans){
            ans=i;
            p.first=3;p.second=4;
        }
        v[i]=s;
    }
    if(!ans){
        cout<<"NO"<<endl;return 0;
    }
    cout<<"YES"<<endl;
    v[ans][p.first]=v[ans][p.second]='+';
    for(int i=1;i<=n;i++) cout<<v[i]<<endl;
}
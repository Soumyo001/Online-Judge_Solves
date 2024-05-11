#include<bits/stdc++.h>
using namespace std;
vector<string>v;
int main(void){
     int n;cin>>n;
     int mx=-1;
     for(int i=0;i<n;i++){
        string s;cin>>s;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a') count++;
        }
        if(count%2!=0){
            if(count==1) s+="a";
            else s.pop_back();
        }
        v.push_back(s);
        mx=max(mx,(int)s.size());
     }
     for(auto i:v){
        int res=mx-(int)i.size();
        res/=2;
        while(res--) cout<<" ";
        cout<<i<<endl;
     }
}
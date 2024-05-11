#include<bits/stdc++.h>
using namespace std;
int main(void){
    int t;cin>>t;
    while(t--){
        int n;string s;cin>>n>>s;
        string t="Timur";
        sort(t.begin(),t.end());
        sort(s.begin(),s.end());
        cout<<(s==t ? "YES":"NO");cout<<endl;
    }
}
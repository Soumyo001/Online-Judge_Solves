#include<bits/stdc++.h>
using namespace std;
const int N=1e4+7;
map<char,multiset<char>>m;
map<char,int>v;
int main(void){
    int n,e;cin>>n>>e;
    for(int i=1;i<=e;i++){
        char a,b;cin>>a>>b;
        m[a].insert(b);
        m[b].insert(a);
        v[a]++;
        v[b]++;
    }
    int rmv=0;
    while(true){
        int max=INT_MIN;
        char c;
        for(auto& it:v){
            if(max<it.second){
                c=it.first;
                max=it.second;
            }
        }
        for(auto& it:m[c]){
            v[it]--;
        }
        if(max<=0) break;
        v[c]=0;
        rmv++;
    }
    cout<<n-rmv<<endl;
}

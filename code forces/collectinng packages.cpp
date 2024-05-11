#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
multiset<pair<int,int>> pac;
int n;
void inputPackage(){
    pac.clear();
    for(int i=1;i<=n;i++){
        int u,v;cin>>u>>v;
        pac.insert({u,v});
    }
}
string shortestPath(){
    int currX=0;
    int currY=0;
    string path="";
    for(auto& pkg:pac){
        int diffX=pkg.first-currX;
        int diffY=pkg.second-currY;
        if(diffX<0 || diffY<0) return "NO\n";
        path+=string(diffX,'R');
        path+=string(diffY,'U');
        currX=pkg.first;
        currY=pkg.second;
    }
    return "YES\n"+path+"\n";
}
int main(void){
    int t;cin>>t;
    while(t--){
        cin>>n;inputPackage();
        cout<<shortestPath();
    }
}
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
vector<pair<int,int>> graph[N];
string s;
int n;
void inputGraph(){
    for(int i=1;i<=n;i++){
        int l,r;cin>>l>>r;
        graph[i].push_back({l,0});
        graph[i].push_back({r,0});
    }
}
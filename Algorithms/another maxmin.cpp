#include<bits/stdc++.h>
using namespace std;
const int n=1e7+10;
int mx[n],mn[n];
int main(void){
    int n,a,b,c,m;cin>>n>>a>>b>>c>>m;
    int x=b;
    int id=0;
    mx[0]=INT_MIN,mn[0]=INT_MAX;
    for(int i=0;i<n;i++){
        x=((a*(long long)x)+c)%m;
        ++id;
        mx[id]=x>mx[id-1]? x:mx[id-1];
        mn[id]=x<mn[id-1]? x:mn[id-1];
    }
    for(int i=1;i<=id;i++) cout<<mx[i]<<" ";
    cout<<endl;
    for(int i=1;i<=id;i++) cout<<mn[i]<<" ";
    cout<<endl;
}
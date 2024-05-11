#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int parent[N],sze[N];
void make(int i){
    parent[i]=i;
    sze[i]=1;
}
int find(int i){
    if(i==parent[i]) return i;
    return parent[i]=find(parent[i]);
}
void Union(int i,int j){
    int a=find(i);
    int b=find(j);
    if(a!=b){
        if(sze[a]<sze[b]) swap(a,b);
        parent[b]=a;
        sze[a]+=sze[b];
    }
}
int main(void){
    for(int i=1;i<=8;i++) make(i);
    Union(2,3);
    Union(1,3);
    Union(7,8);
    Union(4,5);
    Union(5,6);
    Union(5,8);
    //Union(3,7);
    for(int i=1;i<=8;i++) cout<<i<<" "<<parent[i]<<endl;
    int connected_comp=0;
    for(int i=1;i<=8;i++) if(i==find(i)) connected_comp++;
    cout<<connected_comp<<endl;
}
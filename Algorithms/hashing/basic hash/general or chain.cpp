#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>Hash[N];
int hashFunction(int val,int size){
    return val%size;
}
int search(int key,int size){
    if(Hash[hashFunction(key,size)].front()==key) return key;
    for(auto& i:Hash[hashFunction(key,size)]) if(i==key) return key;
    return -1;
}
int main(void){
    int n;cin>>n;
    for(int i=0;i<n;i++) Hash[i].push_back(0);
    while(true){
        int a;cin>>a;
        if(a==-1) break;
        Hash[hashFunction(a,n)].push_back(a);
    }
    while(1){
        int a;cin>>a;
        if(a==-1) break;
        cout<<search(a,n)<<endl;
    }
}
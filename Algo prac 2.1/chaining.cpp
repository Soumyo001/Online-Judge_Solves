#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> Hash[N];
int __hashFunction(int x,int size){
    return (x+2)%size;
}
int search(int key,int size){
    if(Hash[__hashFunction(key,size)].front()==key) return key;
    for(auto& i:Hash[__hashFunction(key,size)]) if(i==key) return key;
    return -1;
}
int main(void){
    int n;cin>>n;
    while(true){
        int x;cin>>x;if(x==-1) break;
        Hash[__hashFunction(x,n)].push_back(x);
    }
    while(true){
        int a;cin>>a;if(a==-1) break;
        cout<<search(a,n)<<endl;
    }
    for(int i=0;i<n;i++){
        for(auto& j:Hash[i]) cout<<j<<" ";
        cout<<endl;
    }
}
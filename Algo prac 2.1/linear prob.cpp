#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int Hash[N];
int __hashfunction(int x,int size,int i=0){
    return (((x+2)%size)+i)%size;
}
void __insert(int x,int size){
    if(Hash[__hashfunction(x,size)]==0){
        Hash[__hashfunction(x,size)]=x;
        return;
    }
    int i=1;
    while(i<size){
        if(Hash[__hashfunction(x,size,i)]==0){
            Hash[__hashfunction(x,size,i)]=x;
            return;
        }i++;
    }
}
int search(int key,int size){
    if(Hash[__hashfunction(key,size)]==key) return key;
    int i=1;
    while(i<size){
        if(Hash[__hashfunction(key,size,i)]==key) return key;
        i++;
    }
    return -1;
}
int main(void){
    int n;cin>>n;
    while(true){
        int x;cin>>x;if(x==-1) break;
        __insert(x,n);
    }
    while(true){
        int a;cin>>a;if(a==-1) break;
        cout<<search(a,n)<<endl;
    }
    for(int i=0;i<n;i++) cout<<Hash[i]<<" ";
}
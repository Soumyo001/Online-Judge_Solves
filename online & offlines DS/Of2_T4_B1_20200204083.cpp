#include<bits/stdc++.h>
using namespace std;
int main(void){
    vector<int> v;
    int n;
    int j=0,key;
    cin>>n;
     for(int i=0;i<n;i++){
        int a;cin>>a;
        v.push_back(a);
    }
    for(int i=1;i<n;i++){
        key=v[i];
        for(j=i-1;j>=0 && key<v[j]; j--){
            v[j+1]=v[j];
        }
        v[j+1]=key;
    }
    for(int i=0;i<n;i++) cout<<v[i]<<" ";
}
#include<bits/stdc++.h>
using namespace std;
int binarySearch(int x,vector<int>& v){
    int lo=0,hi=v.size()-1;
    while(hi-lo>1){
        int mid=(lo+hi)/2;
        if(v[mid]<x) lo=mid+1;
        else hi=mid;
    }
    if(v[lo]==x) return lo;
    else if(v[hi]==x) return hi;
    return -1;
}
int main(void){
    vector<int> v;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        v.push_back(a);
    }
    //sort(v.begin(),v.end());
    int q;cin>>q;
    while(q--){
        int to_find;cin>>to_find;
        cout<<((binarySearch(to_find,v)==-1)? -1:v[binarySearch(to_find,v)]);
        cout<<endl;
    }
}
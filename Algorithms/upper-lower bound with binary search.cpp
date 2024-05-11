#include<bits/stdc++.h>
using namespace std;
vector<int>v={2,4,6,7,8,9,10,12,23,34,45,56,67,78,90,91,123,234,345,456,567,768,789,890};
int Lower_bound(int num){
    int lo=0,hi=v.size()-1;
    while(hi-lo>1){
        int mid=(lo+hi)/2;
        if(v[mid]<num) lo=mid+1;
        else hi=mid;
    }
    if(v[lo]>=num) return v[lo];
    if(v[hi]>=num) return v[hi];
    return -1;
}
int Upper_bound(int num){
    int lo=0,hi=v.size()-1;
    while(hi-lo>1){
        int mid=(lo+hi)/2;
        if(v[mid]>num) hi=mid;
        else lo=mid+1;
    }
    if(v[lo]>num) return v[lo];
    if(v[hi]>num) return v[hi];
    return -1;
}
int main(void){
    int q;cin>>q;
    while(q--){
        int num;cin>>num;
        cout<<Upper_bound(num)<<" "<<Lower_bound(num)<<endl; 
    }
}
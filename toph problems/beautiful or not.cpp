#include<bits/stdc++.h>
using namespace std;
int main(void){
    list<long long> l;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        l.push_back(a);
    }
    l.sort();
    l.unique();
    if(l.back()-l.front()==n-1) cout<<0<<endl;
    else{
        
    }
}
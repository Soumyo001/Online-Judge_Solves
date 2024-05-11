#include<bits/stdc++.h>
using namespace std;
int main(void){
    int t;cin>>t;
    while(t--){
        int n,x;cin>>n>>x;
        n-=2;
        int h=1;
        while(n>0) h++, n-=x;
        cout<<h<<endl;
    }
}
#include<bits/stdc++.h>
using namespace std;
int main(void){
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        int n;cin>>n;
        cout<<"Case "<<i<<": ";
        cout<<floor(log(n)/log(2))+1<<endl;
    }
}
#include<bits/stdc++.h>
using namespace std;
int main(void){
    int t;cin>>t;
    while(t--){
        int n,k,temp;cin>>n>>k;
        char c[n];
        temp=0;
        int ct=0;
        for(int i=0;i<n;i++){
            cin>>c[i];
            if(c[i]=='B' && temp<=0){
                temp=k;
                ct++;
                temp--;
            }else temp--;
        }
        cout<<ct<<endl;
    }
}
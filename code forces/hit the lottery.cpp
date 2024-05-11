#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e12+5;
int main(void){
    int n;cin>>n;
    int ct=0;
    while(n){
        if(n>=100){
            n-=100,ct++;
        }else if(n>=20 && n<100){
           n-=20,ct++;
        }else if(n>=10 && n<20){
             n-=10,ct++;
        }else if(n>=5 && n<10){
             n-=5,ct++;
        }else if(n<5 && n>=1) n-=1,ct++;
    }
    cout<<ct<<endl;
}
//1 5 10 20 100
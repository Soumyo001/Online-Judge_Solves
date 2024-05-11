#include<bits/stdc++.h>
using namespace std;
const double eps=1e-9;
double multiply(double n,int ct){
    double mul=1;
    for(int i=1;i<=ct;i++) mul*=n;
    return mul;
}
int main(void){
    double x;cin>>x;
    int root;cin>>root;
    double lo=1,hi=x;
    while(hi-lo>eps){
        double mid=(lo+hi)/2;
        if(multiply(mid,root)<=x) lo=mid;
        else hi=mid;
    }
    cout<<setprecision(10)<<lo<<" "<<hi<<" "<<pow(x,(double)1/root)<<endl;
}
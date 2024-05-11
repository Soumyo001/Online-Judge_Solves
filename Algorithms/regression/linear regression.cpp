#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
double x[N],y[N];
int main(void){
    int n;cin>>n;
    double sumx=0,sumy=0,sumxy=0,sumx2=0;
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
    for(int i=1;i<=n;i++){
        sumx+=x[i];
        sumy+=y[i];
        sumx2+=(x[i]*x[i]);
        sumxy+=(x[i]*y[i]);
    }
    double b=( n*sumxy - sumx*sumy )/(n*sumx2 - sumx*sumx);
    double a=(sumy-b*sumx)/n;
    cout<<"y = "<<a<<" + "<<b<<" x "<<endl;
}
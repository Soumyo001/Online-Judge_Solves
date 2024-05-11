#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
float x[N],y[N];
int main(void){
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
    float sumx=0,sumy=0,sumx2=0,sumxy=0;
    for(int i=1;i<=n;i++){
        sumx+=log(x[i]);
        sumy+=log(y[i]);
        sumx2+=log(x[i])*log(x[i]);
        sumxy+=log(x[i])*log(y[i]);
    }
    float b=(n*sumxy - sumx*sumy)/(n*sumx2 - sumx*sumx);
    float a=(sumy - b*sumx)/n;
    a=exp(a);
    cout<<a<<" "<<b<<endl;
}
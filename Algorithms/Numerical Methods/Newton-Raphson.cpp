#include<bits/stdc++.h>
using namespace std;
double f(double x){
    return x*x-3*x+2;
}
double df(double x){
    return 2*x-3;
}
int main(void){
    double x0,x1=0,e;cin>>x0;
    cin>>e;
    do{
        x1=x0-(f(x0)/df(x0));
        x0=x1;
    }while(abs(f(x1))>e);
    cout<<x1<<endl;
}
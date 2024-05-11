#include<bits/stdc++.h>
using namespace std;
double f(double y){
    return (y*y)-(9*y)-4;
}
int main(void){
    double a,b,e;cin>>a>>b>>e;
    if(f(a)*f(b)>0){
        cout<<"False Initial guess"<<endl;
        return 0;
    }
    // double x0=(a+b)/2;
    // cout<<"Root "<<x0<<" lies between "<<a<<" and "<<b<<endl;
    // while(abs(f(x0))>e){
    //     if(f(x0)*f(a)<0) b=x0;
    //     else a=x0;
    //     x0=(a+b)/2;
    //     cout<<"Root "<<x0<<" lies between "<<a<<" and "<<b<<endl;
    // }
    // if(f(x0)*f(a)<0) b=x0;
    // else a=x0;
    double x0;
    do{
        //x0=(a+b)/2;
        x0=a-((a-b)*(f(a))/(f(a)-f(b)));
        if(f(x0)*f(a)<0) b=x0;
        else a=x0;
        //cout<<"Root "<<x0<<" lies between "<<a<<" and "<<b<<endl;
    }while(abs(f(x0))>e);
    cout<<"Root "<<x0<<" lies between "<<a<<" and "<<b<<endl;
}
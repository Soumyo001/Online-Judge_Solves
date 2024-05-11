#include<bits/stdc++.h>
using namespace std;
double f(double x){
    return x*x-3*x+2;
}
double df(double x){
    return 2*x-3;
}
double f1(int n,double arr[],double x){
    int i=0;
    double p=arr[i];i++;
    while(n>0){
        p=(p*x)+arr[i];
        i++;n--;
    }
    return p;
}
int main(void){
    double arr[1000];
    double x1=0,x0,e;cin>>e;
    do{
        x0=x1;
        x1=x0-(f(x0)/df(x0));
    }while(abs((x1-x0)/x1)>e);
    cout<<x0<<endl;
    int n,a;
    cin>>n>>a>>x0>>x1;
    for(int i=0;i<a;i++) cin>>arr[i];
    double x2=0,x3=0;
    x3=(f1(n,arr,x1)*(x1-x0))/(f1(n,arr,x1)-f1(n,arr,x0));
    x2=x1-x3;
    while(abs((x2-x1)/x2)>e){
        x0=x1;
        x1=x2;
        x3=(f1(n,arr,x1)*(x1-x0))/(f1(n,arr,x1)-f1(n,arr,x0));
        x2=x1-x3;
    }
    cout<<x2<<endl;
}
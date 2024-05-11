#include<bits/stdc++.h>
using namespace std;
double f(int n,double arr[],double x){
    int i=0;
    double p=arr[i];i++;
    while(n>0){
        p=(p*x)+arr[i];
        i++;n--;
    }
    return p;
}
int main(void){
    double arr[int(1e3)];
    int n,a;cin>>n>>a;
    for(int i=0;i<a;i++) cin>>arr[i];
    double x3=0,x1,x2,e;cin>>x1>>x2>>e;
    double x0=((x2-x1)*f(n,arr,x2))/(f(n,arr,x2)-f(n,arr,x1));
    x3=x2-x0;
    do{
        x1=x2;
        x2=x3;
        double x0=((x2-x1)*f(n,arr,x2))/(f(n,arr,x2)-f(n,arr,x1));
        x3=x2-x0;
    }while(abs((x3-x2)/x3)>e);
    cout<<x3<<endl;
}
#include<bits/stdc++.h>
using namespace std;
double f(int n,double a[],double x){
    int j=n;
    int i=0;
    double p=a[i];
    i++;
    while(j>0){
        p=(x*p)+a[i];
        i++;
        j--;
    }
    return p;
}
int main(void){
    int n,ab;cin>>n>>ab;
    double arr[100];
    for(int i=0;i<ab;i++) cin>>arr[i];
    double a,b,e;cin>>a>>b>>e;
    if(f(n,arr,a)*f(n,arr,b)>0){
        cout<<"False Initial Guess"<<endl;
        return 0;
    }
    double x0=0,pr=0,re=0;
    do{
        x0=(a+b)/2;
        if(f(n,arr,x0)*f(n,arr,a)<0) b=x0;
        else a=x0;
        re=((x0-pr)/x0);
        pr=x0;
    }while(abs(re)>=e);
    cout<<"Root "<<x0<<endl<<"relative error "<<re<<endl;
}
#include<bits/stdc++.h>
using namespace std;
double horners(int n,double a[],double x){
    int j=n;
    int i=0;
    double p=a[i];
    i++;
    while(j>0){
        p=(x*p)+a[i];
        j--;
        i++;
    }
    return p;
}
int main(void){
    int n;double arr[100];
    cin>>n;
    for(int i=0;i<=n;i++) cin>>arr[i];
    double a,b,e;cin>>a>>b>>e;
    if(horners(n,arr,a)*horners(n,arr,b)>0){
        cout<<"False Initial Guess"<<endl;
        return 0;
    }
    // double x0=a-((a-b)*(horners(n,arr,a))/(horners(n,arr,a)-horners(n,arr,b)));
    // while(abs(horners(n,arr,x0))>e){
    //     if(horners(n,arr,x0)*horners(n,arr,a)<0) b=x0;
    //     else a=x0;
    //     x0=(a+b)/2;
    //     x0=a-((a-b)*(horners(n,arr,a))/(horners(n,arr,a)-horners(n,arr,b)));
    // }
    // if(horners(n,arr,x0)*horners(n,arr,a)<0) b=x0;
    // else a=x0;
    double x0;
    do{
        //x0=a-((b-a)*(horners(n,arr,a))/(horners(n,arr,b)-horners(n,arr,a)));
        x0=(a+b)/2;
        if(horners(n,arr,x0)*horners(n,arr,a)<0) b=x0;
        else a=x0;
    }while(abs(horners(n,arr,x0))>e);
    cout<<"Root "<<x0<<" lies between "<<a<<" and "<<b<<endl;
}
#include<bits/stdc++.h>
using namespace std;
double f(double x){
    return x*x*x-x-3;
}
double df(double x){
    return 3*x*x-1;
}
double roundToDecimal(double value,int decimalPlaces=4){
    return round(pow(10,decimalPlaces)*value)/pow(10,decimalPlaces);
}
double funcEvaluation(int n,double arr[],double x){
    int i=0;
    double p=arr[i];i++;
    while(n>0){
        p=(p*x)+arr[i];
        cout<<p<<endl;
        i++;n--;
    }
    return p;
}
int main(void){
    double x0,x1,e;cin>>x0>>e;
    double x=x0;
    double arr[100];int n,i=1;
    cin>>n;for(int i=0;i<(n+1);i++) cin>>arr[i];
    x1=x0-(f(x0)/df(x0));
    x1=roundToDecimal(x1);
    do{
        x0=x1;
        x1=x0-(f(x0)/df(x0));
        x1=roundToDecimal(x1);
    }while(x0!=x1);
    cout<<x1<<endl;
    x0=x;
    do{
        x1=x0-(f(x0)/df(x0));
        x0=x1;
        printf("%d\t%lf\t%lf\t%lf\n",i,x1,f(x1),df(x1));
        i++;
        //x1=roundToDecimal(x1);
    }while(abs(f(x1))>e);
    cout<<x1<<endl;
}
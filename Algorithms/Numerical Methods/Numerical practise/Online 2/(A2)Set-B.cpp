#include<bits/stdc++.h>
using namespace std;
double arr[int(1e3)];
int n;
double f(double x){
    int j=n;
    int i=0;
    double p=arr[i];i++;
    while(j>0){
        p=(p*x)+arr[i];
        i++;j--;
    }
    return p;
}
double roundToDecimal(double value,double decimalPlaces=4){
    return round(value*pow(10,decimalPlaces))/pow(10,decimalPlaces);
}
int main(void){
    double x1,x1t,x2,x2t,x3,e;cin>>n>>x1>>x2>>e;
    x1t=x1,x2t=x2;
    int i=1;
    for(int i=0;i<(n+1);i++) cin>>arr[i];
    x3=x2-(((x2-x1)*f(x2))/(f(x2)-f(x1)));
    do{
        x1=x2;
        x2=x3;
        x3=x2-(((x2-x1)*f(x2))/(f(x2)-f(x1)));
        printf("%d\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n",i,x1,x2,x3,f(x1),f(x2),f(x3));i++;
    }while(abs((x3-x2)/x3)>e);
    cout<<x3<<endl;
    x1=x1t,x2=x2t;
    x3=x2-(((x2-x1)*f(x2))/(f(x2)-f(x1)));i=1;
    x3=roundToDecimal(x3);
    do{
        x1=x2;
        x2=x3;
        x3=x2-(((x2-x1)*f(x2))/(f(x2)-f(x1)));
        x3=roundToDecimal(x3);
        printf("%d\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n",i,x1,x2,x3,f(x1),f(x2),f(x3));i++;
    }while(x3!=x2);
    cout<<x3<<endl;
}

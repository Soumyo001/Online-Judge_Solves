#include<bits/stdc++.h>
using namespace std;
int n;
double f(vector<double>& arr, double x){
    int j=n;
    int i=0;
    double p=arr[i];i++;
    while(j>0){
        p=(p*x)+arr[i];
        i++;j--;
    }
    return p;
}
double df(vector<double>& arr,double x){
    int p=n;
    double ans=0;
    for(int i=0;i<n;i++,p--) ans+=(p*arr[i]*pow(x,p-1));
    return ans;
}
void synthetic_division(vector<double>& __update,double x){
    for(int i=1;i<=n;i++) __update[i]+=(x*__update[i-1]);
}
double MaxRoot(vector<double>& arr){
    return -(arr[1]/arr[0]);
}
int main(void){
    cin>>n;
    vector<double> arr(n+1);
    for(int i=0;i<=n;i++) cin>>arr[i];
    double x0=0,x1=MaxRoot(arr),e;
    double re;
    int itr=0,temp;
    printf("Degree\tRoots\t\tafter iteration\trelative error\n");
    while(n>=1){
        vector<double> updated(arr);
        do{
            itr++;
            x0=x1-(f(arr,x1)/df(arr,x1));
            e=fabs(x1-x0);
            re=fabs(e/x1);
            x1=x0;
        }while(e>0.001);
        printf("%d\t%.6lf\t%d\t\t%lf\n",n,x0,itr,re);
        synthetic_division(updated,x0);
        arr=updated;
        n--;
    }
}
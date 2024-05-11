#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
double f(vector<double>& arr,double x){
    int j=n;
    int i=0;
    double p=arr[i];i++;
    while(i<=n){
        p=(p*x)+arr[i];i++;
    }
    return p;
}
double df(vector<double>& arr,double x){
    double p=n;
    double ans=0;
    for(int i=0;i<n;i++,p--){
        ans+=(p*arr[i]*pow(x,p-1));
    }
    return ans;
}
void syntheticDivision(vector<double>& update,double x){
    for(int i=1;i<=n;i++) update[i]+=(x*update[i-1]);
}
int main(void){
    cin>>n;
    vector<double> arr(n+1,0);
    for(int i=0;i<=n;i++) cin>>arr[i];
    double x1,x0,dx,e;cin>>x1;
    int itr=0;
    while(n>=1){
        vector<double> update(arr);
        do{
            x0=x1-(f(arr,x1)/df(arr,x1));
            e=fabs(x1-x0);
            x1=x0;
            itr++;
        }while(e>=0.001);
        cout<<fixed<<setprecision(6)<<x0<<" ";
        cout<<itr<<endl;
        syntheticDivision(update,x0);
        //for(auto& i:update) cout<<i<<" ";
        //cout<<endl;
        arr=update;
        n--;
    }
}
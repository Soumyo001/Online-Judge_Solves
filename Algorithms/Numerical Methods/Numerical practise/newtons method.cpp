#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
float f(vector<int> arr, float x){
    int j=n;
    int i=0;
    float p=arr[i];i++;
    while (j>0)
    {
        p=(p*x)+arr[i];
        i++;j--;
    }
    return p;
}
float df(vector<int> arr, float x){
    int p=n;
    float sum=0;
    for(int i=0;i<n;i++,p--){
        sum+=(p*arr[i]*pow(x,p-1));
    }
    return sum;
}
void synthetic_division(vector<int>& update, float x){
    for(int i=1;i<=n;i++) update[i]+=(update[i-1]*x);
} 

int main(void){
    cin>>n;
    vector<int> coeff(n+1,0);
    for(int i=0;i<=n;i++) cin>>coeff[i];
    double x0,x1,e;cin>>x1;
    int itr=0;
    while (n>=1)
    {
        vector<int> update(coeff);
        do{
            x0=x1-(f(coeff,x1)/df(coeff,x1));
            e=fabs(x1-x0);
            x1=x0;
            itr++;
        }while(e>=0.001);
        cout<<fixed<<setprecision(6)<<x0<<" ";
        cout<<itr<<endl;
        synthetic_division(update,x0);
        coeff=update;
        n--;
    }
    
}
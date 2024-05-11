#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
int arr[N];
float f(float x){
    int j=n;
    int i=0;
    float p=arr[i];i++;
    while(j>0){
        p=(p*x)+arr[i];
        i++;j--;
    }
    return p;
}
int main(void){
    cin>>n;
    for(int i=0;i<=n;i++) cin>>arr[i];
    float a=-4.358899,b=3.558899,dx=0.1,e=0.0001;
    float x1=a,x2=x1+dx,x0;
    int root=1,itr=0;
    while(x2<b){
        x1=a;
        x2=x1+dx;
        if(f(x1)*f(x2) > 0){
            
        }else{
            do{
                x0=(x1+x2)/2;
                if(f(x1)*f(x0) < 0) x2=x0;
                else x1=x0; 
            }while(fabs(f(x0))>e);
            cout<<root<<" "<<x0<<" "<<itr<<endl;
            root++;
            if(x2>b) break;
        }
        itr++;
        a=x2;
    }
}
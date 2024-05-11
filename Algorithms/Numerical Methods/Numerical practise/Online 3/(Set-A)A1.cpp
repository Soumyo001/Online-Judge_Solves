#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,arr[N];
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
    float a,b,dx,e=0.00001;cin>>a>>b>>dx;
    float x1=a,x2=x1+dx,x0;
    float re;
    int itr=0,root=1;
    printf("Number of Root\tApproximate Root\tNumber of Iteration\tRelative Error\n");
    while(x2<b){
        x1=a;
        x2=x1+dx;
        if(f(x1)*f(x2)>0){
            //  if(x2<b){
            //      a=x2;itr++;continue;
            //  }else break;
        }else{
            do{
                x0=(x1+x2)/2;
                if(f(x0)*f(x1)<0) x2=x0;
                else x1=x0;
                re=fabs((x2-x1)/x2);
            }while(fabs((x2-x1)/x2)>=e);
            printf("%d\t\t%lf\t\t%d\t\t\t%lf\n",root,x0,itr,re);
            root++;
            if(x2>b) break;
        }
        itr++;
        a=x2;
    }
}
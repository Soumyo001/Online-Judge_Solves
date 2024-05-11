#include<bits/stdc++.h>
using namespace std;
void input(int a[],int n){
 for(int i=0;i<n;i++){
    cin>>a[i];
 }
}
void output(int a[],int n){
 for(int i=0;i<n;i++){
    if(a[i]==1) a[i]=0;
    cout<<a[i]<<endl;
 }
}
int main()
{
    int a[1000],b[1000];
    int n,c=0,r=0,i=0;
    cin>>n;
    input(a,n);
  /* for(int i=0; i<=n-1; i++)
    {
        for(int j=i; j<n; j++)
        {
            if(a[j+1]-a[j]>=2)
            {
                c++;
            }
            else
            {
                if(c>0){
                cout<<c+1<<endl;
                c=0;
                break;
                }else{
                 c=0;
                 cout<<c<<endl;
                 break;
                }
            }
        }
    }*/
    /*for(i=0;i<=n-1;){
        if(a[i+1]-a[i]>=2){
            c++;
            i++;
        }else{
          if(c>0){
            b[r]=c+1;
          }else b[r]=0;
          r++;
          i=r;
          c=0;
        }
    }

    output(b,r);*/
    b[n-1]=1;
    for(int i=n-2;i>=0;i--){
        if(a[i+1]-a[i]>=2){
            b[i]=b[i+1]+1;
        }else{
            b[i]=1;
        }
    }
    output(b,n);
}

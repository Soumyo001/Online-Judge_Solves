#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define l int
ll isprime(int x){
    ll c=2,coun=0,i=0;
    l *p;
    p=new int[x];
    while(c)
    {
        for(int i=2;i<c;i++){
            if(c%i==0){
                coun++;
                break;
            }
        }
            if(coun==0){
              p[i]=c;
              i++;
            }
            c++;
            coun=0;
            if(x==i){
                return p[i-1];
                break;
            }
    }
}
l main(void)
{
    l n;
    cin>>n;
    cout<<isprime(n);
}

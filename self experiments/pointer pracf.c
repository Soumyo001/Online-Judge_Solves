#include<stdio.h>
#define ll int
#define sf scanf
#define pf printf
#define f fact
#define s swap
void point(int *i)
{
    scanf("%d",&*i);
}
void swap(int *l,int *k)
{
    int t=*l;
    *l=*k;
    *k=t;
}
int fact(int n,int *x)
{
    for(int i=1;i<=n;i++)
       *x*=i;
    return *x;
}
int main(void)
{
    ll a,*p=&a,b=1,*t=&b,n;
    /*scanf("%d",&a);
    point(&a);
    printf("%d\n",*p);
    scanf("%d%d",&a,&b);
    printf("Before swap %d %d\n",*p,*t);
    s(&a,&b);
    printf("After swap %d %d\n",*p,*t);*/
    b=1;
    sf("%d",&n);
    ll j[n],*r=&j[0];
    f(n,&b);
    pf("%d\n",*t);
    for(int i=0;i<n;i++){
        sf("%d",r);
        r++;}
    r=&j[0];
    for(int i=0;i<n;i++){
        pf("%d\t",*r);
        r++;}
    }


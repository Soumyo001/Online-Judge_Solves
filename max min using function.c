#include<stdio.h>
int maximum(int t,int y,int u,int i);
int maximum(int t,int y,int u,int i)
{
    return (t>y)?(t>u)?(t>i)?t:i:(u>i)?u:i:(y>u)?(y>i)?y:i:(u>i)?u:i;
}
double minimum(int q,int w,int e,int r);
double minimum(int q,int w,int e,int r)
{
    double mini;
    mini=(q<w)?(q<e)?(q<r)?q:r:(e<r)?e:r:(w<e)?(w<r)?w:r:(e<r)?e:r;
    return mini;
}
int main()
{
    int a, b, c, d, max, min;
    printf("Enter a, b, c, d ");
    scanf("%d%d%d%d",&a,&b,&c,&d);
    max=(a>b)?(a>c)?(a>d)?a:d:(c>d)?c:d:(b>c)?(b>d)?b:d:(c>d)?c:d;
    min=(a<b)?(a<c)?(a<d)?a:d:(c<d)?c:d:(b<c)?(b<d)?b:d:(c<d)?c:d;
    printf("%d is max\n",max);
    printf("%d is min\n",min);
    int maxi;
    maxi=maximum(a,b,c,d);
    double mini=minimum(a,b,c,d);
    printf("%d is maximum by function\n",maxi);
    printf("%lf is minimum by function\n",mini);
    int z,x,v,n;
    printf("Enter z,x,v,n ");
    scanf("%d%d%d%d",&z,&x,&v,&n);
    z=max=min;
    if(x>max)
        max=x;
    if(v>max)
        max=v;
    if(n>max)
        max=n;
    if(x<min)
        min=x;
    if(v<min)
        min=v;
    if(n<min)
        min=n;

printf("%d & %d are updated max & min value\n",max,min);

}

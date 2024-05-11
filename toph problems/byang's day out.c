#include<stdio.h>
#define s3 scanf("%d %d %d",&a,&b,&c)
#define s1 scanf("%d",&n)
#define pn printf("No\n")
#define py printf("Yes\n")
int main(void){
    int n,a,b,c;
    s1;
    while(n--){
        s3;
        if(b>a+c){
           pn;continue;}
        if(a>b+c){
          pn;continue;}
        if(c>a+b){
          pn;continue;}
        else
          py;
    }
}
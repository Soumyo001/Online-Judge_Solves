#include<stdio.h>
#define ll long long
void input(int l,ll a[]){
    for(int i=0;i<l;i++) scanf("%lld",&a[i]);
}
int main(void){
    int n,m,count=0;
    ll a[100],b[100];
    scanf("%d",&n);
    input(n,a);
    scanf("%d",&m);
    input(m,b);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
              if(a[i]==b[j]) {count++;break;}
        }
    }
    if(count) printf("1");
    else printf("0");
}

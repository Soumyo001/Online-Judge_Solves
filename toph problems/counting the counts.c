#include<stdio.h>
#define st scanf("%d",&t)
#define pcount printf("%d",count)
int main(void){
    int t,i,count=0;
    st;
    int a[t];
    for(i=0;i<t;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<t;i++) {
        if(a[i]>=80)
            count++;
    }
    pcount;
}
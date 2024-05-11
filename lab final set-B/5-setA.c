#include<stdio.h>
int main(void){
 int d,m,y,d1,m1,y1;
 scanf("%d%d%d",&d,&m,&y);
 scanf("%d%d%d",&d1,&m1,&y1);
 if(d==d1){
    if(m==m1){
        if(y==y1){
            printf("Equal");
        }
        else printf("Not equal");
    }
    else printf("Not equal");
 }
 else printf("Not equal");
}

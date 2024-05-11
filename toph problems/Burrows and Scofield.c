#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define max 100000
int cmprfnc(const void *p,const void *q){
      return *(int *)p-*(int *)q;}
int main(void){
   char s1[max],s2[max];
   gets(s1);gets(s2);
   int a,b,c,x=0,y=0,*p;
   p=(int *)malloc(sizeof(int)*3);
   for(int i=0;i<strlen(s1);i++){
    if(s1[i]>='0'&&s1[i]<='9')
        x+=(s1[i]-'0');
   }
    for(int i=0;i<strlen(s2);i++){
    if(s2[i]>='0'&&s2[i]<='9')
        y+=(s2[i]-'0');
   }
   p[0]=x+y;p[1]=x*y;p[2]=abs(x-y);
   qsort(p,3,sizeof(int),cmprfnc);
   printf("\"%d\"",p[1]);
}

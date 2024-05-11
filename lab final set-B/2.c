#include<stdio.h>
#include<string.h>
int main(void){
 char *cities[]={" UK","INDIA","EGYPT"};
 char a[5],b[5],c[5],d[3];
 strcat(a,cities[0]);
 strcat(b,cities[1]);
 strcat(c,cities[2]);
 d[0]=a[1];
 d[1]=b[4];
 d[2]=c[0];
 for(int i=0;i<3;i++) printf("%c",d[i]);
}

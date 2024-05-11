#include<stdio.h>
#include<string.h>
int main(void){
    char str[100],n[40];
    int p;
    gets(str);
    strcpy(n,str);
    strrev(n);
    p=strcmp(n,str);
    if(p==0) printf("pall");
    else printf("Nt");
}
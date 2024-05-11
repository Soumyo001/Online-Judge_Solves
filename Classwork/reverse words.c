#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(void){
    char a[100];
    int i=0,j=0;
    gets(a);
    while(i<=strlen(a)){
        if(!isalnum(a[i])||i==strlen(a)){
            int t=i-1;
        for(j,t;j<t,t>j;j++,t--){
        char ch=a[j];
        a[j]=a[t];
        a[t]=ch;
        }
            j=i+1;
        }
        i++;
    }
    puts(a);
}
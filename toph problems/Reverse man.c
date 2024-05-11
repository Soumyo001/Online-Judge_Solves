#include<stdio.h>
#include<string.h>
int main(void){
    char a[100],b[100];
    gets(a);
    int j=0;
    for(int i=strlen(a)-1;i>=0;i--){
        if(a[i]!='\0')
           b[j]=a[i];
           j++;
    }
    b[j]='\0';
    printf("%s",a);
}
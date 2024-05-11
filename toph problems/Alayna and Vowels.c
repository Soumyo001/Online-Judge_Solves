#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(void){
char a[1000];
gets(a);
int count=0;
for(int i=0;i<strlen(a);i++)
    if(a[i]=='A'||a[i]=='E'||a[i]=='I'||a[i]=='O'||a[i]=='U'||a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u') count++;

    printf("%d",count);
}

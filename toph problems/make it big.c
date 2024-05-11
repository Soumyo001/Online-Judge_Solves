#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void swap(char *a,char b,char c){
    char temp;
    temp=*(a+b);
    *(a+b)=*(a+c);
    *(a+c)=temp;
}
int main(void){
    int t;
    scanf("%d",&t);
    while(t--){
    long long int temp,x;
    char a[200],b[200];
    fflush(stdin);
    gets(a);
    a[strlen(a)]='\0';
    for(int i=0;i<strlen(a);i++){
        b[i]=a[i];
    }
    for(int i=0;i<strlen(a);i++){
        for(int j=0;j<strlen(a);j++){
            if(i!=j){
                for(int k=0;k<strlen(a);k++){
                    for(int l=0;l<strlen(a);l++){
                        if(k!=l){
                            swap(a,i,j);
                            swap(a,k,l);
                            temp=strtoll(a,NULL,10);
                            x=strtoll(b,NULL,10);
                        }
                    }
                }
            }
        }
    }
    if(temp>x) printf("%lld\n",temp);
    else printf("%lld\n",x);
    }
}
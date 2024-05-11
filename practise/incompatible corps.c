#include<stdio.h>
#include<string.h>
int main(void){
    int r,c,count=0;;
    scanf("%d%d",&r,&c);
    char a[100][100];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%s",&a[i][j]);
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(a[i][j]=='.'){
            if(a[i-1][j]!='*'&&a[i+1][j]!='*'&&a[i][j-1]!='*'&&a[i][j+1]!='*')
               count++;}
        }
    }
    printf("%d",count);
}
#include<stdio.h>
int main(void){
    FILE *f1;
    FILE *f2;
    FILE *f3;
    f1=fopen("file1.txt","r");
    f2=fopen("file2.txt","r");
    f3=fopen("file3.txt","w");
    char arr[2000];
    while(!feof(f1)){
        fgets(arr,2000,f1);
        fputs(arr,f3);
    }
    fputs(" ",f3);
    fclose(f1);
    fclose(f3);
    f3=fopen("file3.txt","a");
    while(!feof(f2)){
        fgets(arr,2000,f2);
        fputs(arr,f3);
    }
    fclose(f2);
    fclose(f3);
}

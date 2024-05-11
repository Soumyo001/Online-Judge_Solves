#include<stdio.h>
int main (void){
    char a[2000],b[2000];
    gets(a);int i=0;
    fflush(stdin);
    FILE *f;
    if((f=fopen("Risal.txt","w"))==NULL){printf("Can't open\n");return 1;};
    fputs(a,f);
    fclose(f);
    f=fopen("Risal.txt","r");
    while(!feof(f)){
    fgets(b,1000,f);
    puts(b);
    //if(a[i]!='\0'){b[i]=putchar(fgetc(f));i++;}
    //else break;
    }
    printf("Success");
    fclose(f);
}

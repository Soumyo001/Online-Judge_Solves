#include<stdio.h>
#include<string.h>
int main(void)
{
    int i=0;
    char name[510000];
    gets(name);
    int length=strlen(name);
    FILE*file;
    file=fopen("test.txt","a");
    if(file==NULL) printf("False cause");
    else printf("file is successfully opened\n");
    fputs(" ",file);
        while(1)
        {
            //if(!feof(file)) putchar(fgetc(file));
            if(name[i]!='\0') {fputc(name[i],file);i++;}
            else break;
        }
        printf("\n");
        printf("successfully written");
        fclose(file);
}

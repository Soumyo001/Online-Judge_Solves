#include<stdio.h>
#include<string.h>
typedef struct studetails {
    char name [50],id[20],number[20];
}st;
int main(void){
    FILE *f1;
    st details[15];
    char shift[]={'i','d','e','s'},ch;int k=0;
    if((f1=fopen("Details.txt","w"))==NULL) {printf("Cannot open File.\n");return 1;}
    while(1){
        scanf("%c",&ch);
        if(k==15) printf("No empty space.\n");
        if(ch=='i'){
            fflush(stdin);
            gets(details[k].name);
            fflush(stdin);
            gets(details[k].id);
            fflush(stdin);
            gets(details[k].number);k++;
        }
        else if(ch=='d') k--;
        else if(ch=='e') break;
        else if(ch=='s'){
            for(int x=0;x<k;x++){
                fprintf(f1,"%s\n%s\n%s\n",details[x].name,details[x].id,details[x].number);
                fputs("\n",f1);
            }
            printf("Successfully Stored\n");
        }
    }
    fclose(f1);
    f1=fopen("Details.txt","r");
    FILE *f3;
    if((f3=fopen("Details2.txt","w"))==NULL) printf("Cannot Open");
    char c[1000];
    while(!feof(f1)){
        fgets(c,1000,f1);
        fputs(c,f3);
    }
    printf("Successfully written in another file\n");
    fclose(f1);
    fclose(f3);
    FILE *f2;
    if((f2=fopen("separated lines.txt","r"))==NULL) printf("Cannot open");
    char s[1000];
    while(!feof(f2)){fgets(s,1000,f2);puts(s);}
    fclose(f2);
}
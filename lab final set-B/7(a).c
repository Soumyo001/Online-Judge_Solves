#include<stdio.h>
int main(void){
   char ch;
   FILE *fp;
   fp=fopen("data.txt","w+");
   fclose(fp);
   fp=fopen("data.txt","r");
   while((ch=fgetc(fp))!=EOF){
    printf("%c",ch);
   }
   fclose(fp);
   return 0;
}

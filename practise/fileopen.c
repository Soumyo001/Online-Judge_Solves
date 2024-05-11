#include<stdio.h>
int main(void){
char k[1000];
  FILE *x,*y;
  if((x=fopen("D:\\Riot Games\\VALORANT\\live\\Manifest_DebugFiles_Win64.txt","r"))==NULL) printf("Cannot open file");
  if((y=fopen("Copy.txt","w"))==NULL) printf("Not opened");
  while(!feof(x)){
    fgets(k,1000,x);
    puts(k);
    fprintf(y,"%s",k);
    //fputs(k,y);
  }
  fclose(y);
  y=fopen("Copy.txt","a");
  gets(k);
  fprintf(y,"%s",k);
  fclose(x);
  fclose(y);
}

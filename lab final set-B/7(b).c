#include<stdio.h>
int main(void){
  int num[4];
  int i=0,total=0;
  FILE *fptr;
  fptr=fopen("data.txt","r");
  if(fptr==NULL) printf("File does not exist");
  for(i=0;i<4;i++){
    fscanf(fptr,"%d,",&num[i]);
  }
  for(i=3;i>=0;i--){
    if(i==1&&i==3){
        num[i]=num[i]+num[i-1];
    }
    total=total+num[i];
  }
  printf("Total = %d",total);
  fclose(fptr);
}

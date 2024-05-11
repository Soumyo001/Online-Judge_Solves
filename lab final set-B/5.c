#include<stdio.h>
struct student{
  int roll,age;
  char address[2000],name[1000];
};
int main(void){
 struct student s1[12];
 for(int i=0;i<12;i++){
    scanf("%d%d",&s1[i].roll,&s1[i].age);
    gets(s1[i].address);
    fflush(stdin);
    gets(s1[i].name);
    fflush(stdin);
 }
 for(int i=0;i<12;i++){
    if(s1[i].roll%2==0){
        printf("%d\n%d\n",s1[i].roll,s1[i].age);
        puts(s1[i].address);
        puts("\n");
        puts(s1[i].name);
        puts("\n");
    }
 }
}

#include<stdio.h>
int main(void){
 struct player{
  int playnum;
  char name[30];
 };
 struct player p1={18,"Sakib"};
 struct player p2={18,"Sakib"};
 if(p1==p2) printf("Match");
 else printf("No");
}

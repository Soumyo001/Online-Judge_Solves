#include<stdio.h>
int main(void){
 struct str{
  int s1;
  char st[30];
 };
 struct str s[]={{1,"st 1"},{2,"st2"},{3,"st3"},{4,"st4"}};
 printf("%s  %d",s[1].st,(*(s+3)).s1);
}

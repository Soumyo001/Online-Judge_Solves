#include<stdio.h>
int main(){
    struct node{int a,b,c,d;};
    struct node num ={8,4,9,2};
 struct node *ptr=&num;
 printf("%d\n",*((int*)ptr+3-(2-1)*2));
 return 0;
}

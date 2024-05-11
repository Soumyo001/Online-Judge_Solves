#include<stdio.h>
#include<string.h>
int main(void){
 char str[]={"14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482542117067"};
 int t;
 scanf("%d",&t);
 while(t--){
        int i;
    scanf("%d",&i);
    printf("%c\n",str[i-1]);
    }
}

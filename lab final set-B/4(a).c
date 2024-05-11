#include<stdio.h>
int main(void){
   struct forest{
     int trees,animals;
   }F1,*F2;
   F1.trees=1000;
   F1.animals=20;
   F2=&F1;
   printf("%d ",(*F2).animals);
}

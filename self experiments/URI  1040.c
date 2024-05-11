#include<stdio.h>
int main()
{
  float n1,n2,n3,n4,n5,average;
  scanf("%f%f%f%f",&n1,&n2,&n3,&n4);
  average = (n1*2+n2*3+n3*4+n4)/10;
  printf("Media: %.1f\n",average);
  if(average>=7.0)
  printf("Aluno aprovado.\n");
  else if(average>=5.0&&average=<6.9)
  {
      scanf("%f",&n5);
      printf("Nota do exame: %.1f\n",n5);
      if((n5+average)/2>=5.0)
      printf("Aluno aprovado.\n");
      else
      printf("Aluno reprovado.\n");
      printf("Media Final: %.1f\n",(n5+average)/2.0);
  }
  else
  printf("Aluno reprovado.\n");
  return 0;
}

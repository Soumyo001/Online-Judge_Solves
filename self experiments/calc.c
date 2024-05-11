#include<stdio.h>
#include<math.h>
int main(void)
{
long long int n1,n2;
char op;
printf("Enter two numbers ");
scanf("%lld%lld",&n1,&n2);

printf("Enter operator \n");
scanf(" %c",&op);

switch(op)
{
case'+':
    printf("Addition is %lld\n",n1+n2);
    break;
case'-':
    {
        if(n1>n2)
            printf("Subtraction is %lld\n",n1-n2);
        else
            printf("Subtraction is %lld\n",n2-n1);
    }
    break;
case'*':
    printf("Multiplication is %lld\n",n1*n2);
    break;
case'/':
    printf("Division is %lld\n",(float)n1/n2);
    break;
default:
    printf("Wrong Choice\n");
}

}

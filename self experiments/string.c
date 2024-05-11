#include<stdio.h>
#include<string.h>
struct info
{
   char ch[180];
   int age;
   float salary;
};
int main(void)
{
    char ch[40],fu[50];
    gets(ch);
    gets(fu);
    printf("%s\n%s\n",ch,fu);
    struct info person[5];
    for(int i=0;i<5;i++)
    {
        printf("Enter info for person %d\n",i+1);
        printf("Name: ");
        fflush(stdin);
        gets(person[i].ch);
        printf("Age: ");
        scanf("%d",&person[i].age);
        printf("Salary: ");
        scanf("%f",&person[i].salary);
    }
    for(int i=0;i<5;i++)
    {
        printf("Info for person %d\n",i+1);
        printf("Name: %s\n",person[i].ch);
        printf("Age: %d\n",person[i].age);
        printf("Salary: %.3f\n",person[i].salary);
    }
}

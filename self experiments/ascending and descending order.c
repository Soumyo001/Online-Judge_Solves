#include<stdio.h>
int main(void)
{
    int x;
    printf("Ascending order press 1\ndescending order press 2\n");
    scanf("%d",&x);
    switch(x)
    {
    case 1:
        {
             int a,b,c;
    printf("Enter 3 integer numbers ");
    scanf("%d%d%d",&a,&b,&c);
    if(a>b)
    {
        if(a>c)
        {
            if(b>c)
            {
                printf("ascending order: %d %d %d\n",c,b,a);
            }
            else
            {
                printf("ascending order: %d %d %d\n",b,c,a);
            }
        }
        else
        {
            printf("ascending order: %d %d %d\n",b,a,c);
        }
    }
    else
    {
        if(b>c)
        {
            if(c>a)
            {
                printf("ascending order: %d %d %d\n",a,c,b);
            }
            else
            {
                printf("ascending order: %d %d %d\n",c,a,b);
            }
        }
        else
        {
            printf("ascending order: %d %d %d\n",a,b,c);
        }
    }
    break;
        }
    case 2:
        {
             int a,b,c;
    printf("Enter 3 integer numbers ");
    scanf("%d%d%d",&a,&b,&c);
    if(a>b)
    {
        if(a>c)
        {
            if(b>c)
            {
                printf("descending order: %d %d %d\n",a,b,c);
            }
            else
            {
                printf("descending order: %d %d %d\n",a,c,b);
            }
        }
        else
        {
            printf("descending order: %d %d %d\n",c,a,b);
        }
    }
    else
    {
        if(b>c)
        {
            if(c>a)
            {
                printf("descending order: %d %d %d\n",b,c,a);
            }
            else
            {
                printf("descending order: %d %d %d\n",b,a,c);
            }
        }
        else
        {
            printf("descending order: %d %d %d\n",c,b,a);
        }
    }
        }
        break;
    }
}


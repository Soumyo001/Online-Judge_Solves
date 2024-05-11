#include<bits/stdc++.h>
#define error 0.00001
using namespace std;

//Horner's Methods to evaluate polynomial
float horners(float p[], int n, float x)
{
    float b = 0;
    int i;
    for(i=0; i<=n; i++)
    {
        b = b*x + p[i];
        //b += pow(x,(n-i))*p[i];
    }
    return b;
}
int main()
{
    printf("\n Enter the highest degree of the equation: ");
    int n,i;
    scanf("%d",&n);

    float x1, x2, a, b, xr,ds, f1, f2, fr, e;
    ds=0.1;

    //x1=a; x2 = x1+ds;
    float  coeff[n+1], q[n+1];

    printf("\n Enter values of coefficients: ");
    for(i=0;i<=n;i++)
    {
        printf("\n Coefficient x[%d] = ", n-i); // 2×3 – 6×2 + 2x – 1
        scanf("%f",&coeff[i]);
    }
    float xmax = sqrt(pow((coeff[1]/coeff[0]),2)-2*(coeff[2]/coeff[0]));
    printf("Possible interval %f and %f\n", -xmax, xmax);
    b = xmax;
    a=-xmax;
    //printf("Enter the lower and upper limit:\n");
    //scanf("%f%f", &a, &b);

    //printf("Enter the size of interval:\n");
    //scanf("%f", &ds);
   int itrCount = 0;
   int rootCount = 1;
   float err;

   printf("Number of Root\tApproximate Root\tNumber of Iteration \t Relative Error\n");
    while(x2<b)
    {
        x1 = a;
        x2 = x1 + ds;

        //printf("%f %f\n",f1,f2);
        if (horners(coeff, n, x1)*horners(coeff, n, x2)>0)
        {
            //printf("Wrong Guess\n");
          //  break;
        }
        else
        {
            do{
                    xr = (x1+x2)/2;

                    //printf("%f%f\n",xr, fr);

                    if((horners(coeff, n, x1)*horners(coeff, n, xr))<0)
                    {
                        x2=xr;
                    }
                    else
                    {
                        x1=xr;
                    }
                    err = fabs((x2-x1)/x2);

               } while(fabs((x2-x1)/x2)>=error);

               printf("%d \t\t %f \t\t %d \t\t\t %f\n", rootCount, xr,itrCount, err);
               rootCount++;
               if(x2>b)
               {
                   break;
               }

        }
           itrCount++;
        a = x2;
    }
}
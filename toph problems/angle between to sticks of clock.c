#include <stdio.h>
int main()
/*{
    int h, m;
    double p;
    scanf("%d %d", &h, &m);
    p=0.5*m+h*30-m*6;
    if(p<0) {
        p=p*(-1);
    }
    if(p<=180) {
    printf("%lf\n", p);
        }
    else if(p>180) {
        printf("%lf\n", 360-p);
    }
    return 0;
}*/
{
    int h,m;float c;
    scanf("%d%d",&h,&m);
    c=0.5*(60*h-11*m);
    if(c<0)
    printf("%f",c*=(-1));
    if(c<=180)
            printf("%f",c);
    if(c>180)
            printf("%f",360-c);
    return 0;
}

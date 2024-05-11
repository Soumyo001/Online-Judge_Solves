#include <stdio.h>
int main()
{
    long long int a, i, k=1;
    scanf("%lld", &a);
    if(a>=20) {
        printf("0000\n");
    }
    else {
        for(i=1; i<=a; i++) {
            k=k*i;
        }
        if(k%10000>=0 && k%10000<=9) {
            printf("000%lld\n", k%10000);
        }
        else if(k%10000>=10 && k%10000<=99) {
            printf("00%lld\n", k%10000);
        }
        else if(k%10000>=100 && k%10000<=999) {
            printf("0%lld\n", k%10000);
            }
        else if(k%10000>999) {
        printf("%lld\n", k%10000); }
    }
    return 0;
}
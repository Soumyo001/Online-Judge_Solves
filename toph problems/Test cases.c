#include<stdio.h>
int main(void)
{
    int n,cpul,meml;
    int a,cpu,mem;
    int wa=0,memli=0,cpuli=0;
    scanf("%d%d%d",&n,&cpul,&meml);
    while(n--)
    {
        scanf("%d%d%d",&a,&cpu,&mem);
        if(cpu>cpul){
            cpuli=1;
            break;
        }
        if(mem>meml){
            memli=1;
            break;
        }
        if(a!=0){
            wa=1;
            break;
        }
    }
    if(cpuli)
        printf("CLE\n");
    else if(memli)
        printf("MLE\n");
    else if(wa)
        printf("WA\n");
    else
        printf("AC\n");
}

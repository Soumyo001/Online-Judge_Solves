#include<stdio.h>
int main(void)
{
    int p,q,t,i,turn,klee,jean,pick=1;
    scanf("%d",&t);
    klee=1;
    jean=2;
    for(i=1;i<=t;i++)
    {
        scanf("%d%d",&p,&q);
        turn=p;
        for(turn;turn>0;turn-=q)
        {
            switch(pick)
            {
            case 1:
                {
                    p-=q;
                    pick++;
                    break;
                }
            case 2:
                {
                    p-=q;
                    pick--;
                    break;
                }
            }
        }
    }
}

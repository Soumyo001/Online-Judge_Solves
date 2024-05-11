#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
int weight=20,height=20,x,y,Fruitx,Fruity,gameover,count=0,flag,score=0;
int tailX[100],tailY[100];
void setup()
{
    gameover=0;
    x=weight/2;
    y=height/2;
    label1 : ;
    Fruitx=rand()%20;
    if(Fruitx==0)
        goto label1;
    label2 : ;
    Fruity=rand()%20;
    if(Fruity==0)
        goto label2;
}
void draw()
{
    int i,j,k;
    system("cls");
    for(i=0;i<weight;i++)
    {
        for(j=0;j<height;j++)
        {
            if(i==0||i==height-1||j==0||j==weight-1)
            {
                printf("#");
            }
            else
            {
                if(i==x&&j==y)
                    printf("O");
                else if(i==Fruitx&&j==Fruity)
                    printf("F");
                else
                {
                    int ch=0;
                    for(k=0;k<count;k++)
                    {
                       if(i==tailX[k]&&j==tailY[k])
                       {
                           printf("o");
                           ch=1;
                       }
                    }
                    if(ch==0)
                        printf(" ");
                }
            }
        }
        printf("\n");
    }
}
void input()
{
    if(kbhit())
    {
        switch(getch())
        {
        case 'a':
            flag=1;
            break;
            case 'd':
                flag=2;
                break;
            case 'w':
                flag=3;
                break;
            case 's':
                flag=4;
                break;
            case 'x':
                gameover=1;
                break;
        }
    }
}
void logic()
{
    int i;
    int prevX=tailX[0];
    int prevY=tailY[0];
    tailX[0]=x;
    tailY[0]=y;
    int prev2X,prev2Y;
    for(i=1;i<=count;i++)
    {
      prev2X=tailX[i];
      prev2Y=tailY[i];
      tailX[i]=prevX;
      tailY[i]=prevY;
      prevX=prev2X;
      prevY=prev2Y;
    }
    switch(flag)
    {
    case 1:
        y--;
        break;
    case 2:
        y++;
        break;
    case 3:
        x--;
        break;
    case 4:
        x++;
        break;
    default:
        break;
    }
    if(x<0||x>weight||y<0||y>height)
        gameover=1;
    for(i=0;i<count;i++)
    {
        if(x==tailX[i]&&y==tailY[i])
            gameover=1;
    }
    if(x==Fruitx&&y==Fruity)
    {
        label3 : ;
    Fruitx=rand()%20;
    if(Fruitx==0)
        goto label3;
    label4 : ;
    Fruity=rand()%20;
    if(Fruity==0)
        goto label4;
    count++;
    score+=10;
    }
}
int main()
{
    int level=100;
    label5 : ;
    setup();
    while(!gameover)
    {
       draw();
       input();
       logic();
       Sleep(level);
    }
    return 0;
}

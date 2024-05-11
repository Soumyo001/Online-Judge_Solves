#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
int height=20,weight=20,gameover;
int x,y,Fruitx,Fruity,flag,score,count=0;
int tailX[100],tailY[100];
void setup()
{
    gameover=0;
    x=height/2;
    y=weight/2;
    Fruitx=rand()%20;
    label1 : ;
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
                for(int k=0;k<count;k++)
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
    printf("SCORE = %d\n",score);
}
void input()
{


    if(_kbhit())
    {
        switch(_getch())
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
    int prev2X,prev2Y;
    tailX[0]=x;
    tailY[0]=y;
    for(i=1;i<count;i++)
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
        {
            gameover=1;
            Beep(5000,600);
        }
    for(i=0;i<count;i++)
    {
        if(x==tailX[i]&&y==tailY[i])
        {
            gameover=1;
            Beep(5000,600);
        }
    }
    if(x==Fruitx&&y==Fruity)
    {
    Beep(500,550);
    Fruitx=rand()%20;
    label3 : ;
    if(Fruitx==0)
        goto label3;
    label4 : ;
    Fruity=rand()%20;
     if(Fruity==0)
        goto label4;
    score+=10;
    count++;
    }
}
int main()
{
    int d=50;
    char p;
    label5 : ;
    setup();
    while(!gameover)
    {
    draw();
    input();
    logic();
    Sleep(d);
    }
    printf("Want to try again? \n");
    scanf_s("%c",&p);
    if(p=='Y'||p=='y')
        goto label5;
    else
        printf("Thank you! If you want to buy the game contact publisher\n");
    return 0;
}

#include<stdio.h>
int main(void)
{
    int bdate,bmonth,byear,cdate,cmonth,cyear,r1,r2,r3;
    printf("Enter your birth date in DD//MM//YY format ");
    scanf("%d%d%d",&bdate,&bmonth,&byear);
    printf("Enter current date in DD//MM//YY format ");
    scanf("%d%d%d",&cdate,&cmonth,&cyear);
    if(cdate>=bdate)
    {
        r1=cdate-bdate;
    }
    else if(cmonth==1||cmonth==3||cmonth==7||cmonth==8||cmonth==5||cmonth==10||cmonth==12)
    {
        cmonth--;
        cdate+=31;
        r1=cdate-bdate;
    }
    else if(cmonth==2)
    {
        if((cyear%4==0&&cyear%100!=0)||(cyear%400==0))
        {
            cmonth--;
            cdate+=29;
            r1=cdate-bdate;
        }
        else
        {
            cmonth--;
            cdate+=28;
            r1=cdate-bdate;
        }
    }
    else
    {
        cmonth--;
        cdate+=30;
        r1=cdate-bdate;
    }
    if(cmonth>=bmonth)
    {
        r2=cmonth-bmonth;
    }
    else
    {
        cyear--;
        cmonth+=12;
        r2=cmonth-bmonth;
    }
    r3=cyear-byear;
    printf("Your age is: %d-%d-%d ",r1,r2,r3);


}

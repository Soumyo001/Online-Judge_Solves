#include<stdio.h>
int main(void){
    int t,courses,f=0,d=1;
    double credit,sum=0,m,count=0;
    scanf("%d",&t);
    while(t--){
        sum=0;
        count=0;
        f=0;
        scanf("%d",&courses);
        for(int i=0;i<courses;i++){
            scanf("%lf%lf",&m,&credit);
            if(m<40)
                f++;
            else if(m>=80)
                sum+=(4.00*credit);
            else if(m>=75)
                sum+=(3.75*credit);
            else if(m>=70)
                sum+=(3.50*credit);
            else if(m>=65)
                sum+=(3.25*credit);
            else if(m>=60)
                sum+=(3.00*credit);
            else if(m>=55)
                sum+=(2.75*credit);
            else if(m>=50)
                sum+=(2.50*credit);
            else if(m>=45)
                sum+=(2.25*credit);
            else if(m>=40)
                sum+=(2.00*credit);
            count+=credit;
        }
        if(f==0)
            printf("Case %d: %.2lf\n",d++,sum/count);
        else
        printf("Case %d: Sorry, you have failed in %d %s!\n",d++,f,(f==1)?"course":"courses");
    }
}

//exp no,name of the exp,theory,working formula,apparatues,data table,calculation,percentage error,result,discussion.
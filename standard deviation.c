#include<stdio.h>
#include<math.h>
int stdev(int x,int y,int z,int a,int b){
    int avg,sum;
    avg=(x+y+z+a+b)/5;
    sum=pow(x-avg,2)+pow(y-avg,2)+pow(z-avg,2)+pow(a-avg,2)+pow(b-avg,2);
    return sqrt(sum/5);
}
long long int fact(long long int x){
    if(x==1)
        return 1;
    else
        return x*fact(x-1);
}
int power(int i,int j){
    if(j==0) return 1;
    else{
    return i*power(i,j-1);}
}
int main(void){
    int a,b,c,d,e;
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    printf("%d\n",stdev(a,b,c,d,e));
    //factorial
    long long int x;
    scanf("%lld",&x);
    printf("%lld\n",fact(x));
    //power
    int y,z;
    scanf("%d %d",&y,&z);
    printf("%d",power(y,z));
}
#include<stdio.h>
#include<stdlib.h>
int cmprfnc(const void *p,const void *q){
    return *(int *)p-*(int *)q;
}
void input(int a[],int len){
    for(int i=0;i<len;i++) scanf("%d",&a[i]);
}
void output(int a[],int len){
    for(int i=0;i<len;i++) printf("%d ",a[i]);
}
int main(void){
    int n,m,*p,*q,*r,k=0;scanf("%d%d",&n,&m);
    p=(int *)malloc(n*sizeof(int));
    q=(int *)malloc(m*sizeof(int));
    r=(int *)malloc((n+m)*sizeof(int));
    input(p,n);input(q,m);
    for(int i=0;i<n;i++){
        r[k]=p[i];k++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(p[i]==q[j]) q[j]=0;
        }
    }
    for(int i=0;i<m;i++){
        if(q[i]==0) continue;
        else {r[k]=q[i];k++;}
    }
    qsort(r,k,sizeof(int),cmprfnc);
    for(int i=0; i<k; i++) {
        if(i==0) printf("%d", r[i]);
        else printf(" %d", r[i]);
    }
    free(p);free(q);free(r);
}
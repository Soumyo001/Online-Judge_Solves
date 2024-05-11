#include<stdio.h>
#include<string.h>
int main(void){
    char a[100],b[100],ch;
    int l,j,r=0,k=1,n=0;
    gets(a);
    for(int i=0;i<strlen(a);i++) {
        if(a[i]=='('||a[i]=='{'||a[i]=='['){
            b[r]=a[i];
            r++;
            n++;
        }
        else{
            r--;
            ch=b[r];
            if(a[i]==')')
                if(ch!='('){
                     k=0;
                     break;
                }
            if(a[i]=='}')
                if(ch!='{'){
                    k=0;
                    break;
                }
            if(a[i]==']')
                if(ch!='['){
                    k=0;
                    break;
                }
        }
    }
    if(n==strlen(a))
         k=0;
    if(k)
      printf("Yes\n");
    else
      printf("No\n");

}

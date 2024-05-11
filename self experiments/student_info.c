#include<stdio.h>
#include<string.h>
typedef struct studentInfo{
  char name[2000],number[20];
}s;

int main(void){
    int k=1,x=0;
    char a;
    s info[k];
    for(;;){
        scanf("%c",&a);
        fflush(stdin);
        if(a=='a'){
            gets(info[x].name);
            fflush(stdin);
            gets(info[x].number);
            fflush(stdin);
            x++;k++;
        }
        else if(a=='v'){
            for(int i=0;i<k;i++){
                puts(info[i].name);
                puts(info[i].number);
            }
        }
        else if(a=='d') k--;
        else if(a=='s'){
            char name1[2000];
            gets(name1);
            for(int i=0;i<k;i++){
                if(strcmp(name1,info[i].name)==0){
                          puts(info[i].name);
                          puts(info[i].number);
                          break;
                }
            }
        }
        else if(a=='e') break;
    }

}

#include<bits/stdc++.h>
using namespace std;
class Vector{
 public:
     double x,y;
     string ch;char c[1000];
     Vector(){};
     Vector(string h,double x1,double y1){
       ch=h;x=x1;y=y1;
     }
};
int main(void){
   Vector v[2];
   char s[1000];int i=0;
   //getline(cin,v.ch);
   //gets(v.c);
   FILE *fp;
   if((fp=fopen("text.txt","w"))==NULL) cout<<"Can't open file"<<endl;
   //while(i<3){gets(v.c);fprintf(fp,"%s\n",v.c);i++;}
   //fputs(v.c,fp);
   for(int i=0;i<2;i++){
     gets(v[i].c);
     fputs(v[i].c,fp);fputs("\n",fp);
   }
    puts(v[1].c);
}

#include<bits/stdc++.h>
using namespace std;
#define fast(a) for(int i=0;i<a;i++)
class studentInfo{
    public:
    char name[1000];int ID;
    double totalGPA,hsc,ssc;
    studentInfo(){}
};
int main(void){
    studentInfo si[7];double data[7];int i=0;
    FILE *f1;
    if((f1=fopen("student_data.txt","r"))==NULL){exit(1);}
    while(!(feof(f1))){
        fscanf(f1, "%d%s%lf%lf%lf", &si[i].ID,&si[i].name,&si[i].totalGPA,&si[i].hsc,&si[i].ssc);i++;
    }
    fclose(f1);
   for(int i=0;i<7;i++){
        data[i] = si[i].totalGPA;
    }
    for(int i=0;i<6;i++){
         for(int j=i+1;j<7;j++){
             if(data[i]<data[j]){
                 int t=data[i];
                 data[i]=data[j];
                 data[j]=t;
             }
         }
     }
    FILE *f2;
    if((f2=fopen("total_gpa_analysis.txt","w"))==NULL){exit(1);}
    fputs("For Bangla Medium:",f2);
    fputs("\n",f2);
    fputs("===================\n",f2);
    fputs("Total GPA: ",f2);fprintf(f2,"%f",10.00);
    fputs("\n",f2);
    fputs("===================\n",f2);
    for(int i=0;i<7;i++){
        if(si[i].totalGPA==10.00){
            fputs("ID: ",f2);fprintf(f2,"%d",si[i].ID);fputs(" ; ",f2);
            fputs("Name: ",f2);fprintf(f2,"%s",si[i].name);fputs("\n",f2);
        }
    }
    fputs("Total GPA: ",f2);fprintf(f2,"%f",9.67);
    fputs("\n",f2);
    fputs("===================\n",f2);
    for(int i=0;i<7;i++){
        if(si[i].totalGPA==9.67){
            fputs("ID: ",f2);fprintf(f2,"%d",si[i].ID);fputs(" ; ",f2);
            fputs("Name: ",f2);fprintf(f2,"%s",si[i].name);fputs("\n",f2);
        }
    }
    fputs("Total GPA: ",f2);fprintf(f2,"%f",9.55);
    fputs("\n",f2);
    fputs("===================\n",f2);
    for(int i=0;i<7;i++){
        if(si[i].totalGPA==9.55){
            fputs("ID: ",f2);fprintf(f2,"%d",si[i].ID);fputs(" ; ",f2);
            fputs("Name: ",f2);fprintf(f2,"%s",si[i].name);fputs("\n",f2);
        }
    }
    fputs("For English Medium:",f2);
    fputs("\n",f2);
    fputs("===================\n",f2);
    fputs("Total GPA: ",f2);fprintf(f2,"%f",8.0);
    fputs("\n",f2);
    fputs("===================\n",f2);
    for(int i=0;i<7;i++){
        if(si[i].totalGPA==8.0){
            fputs("ID: ",f2);fprintf(f2,"%d",si[i].ID);fputs(" ; ",f2);
            fputs("Name: ",f2);fprintf(f2,"%s",si[i].name);fputs("\n",f2);
        }
    }
    fputs("Total GPA: ",f2);fprintf(f2,"%f",7.5);
    fputs("\n",f2);
    fputs("===================\n",f2);
    for(int i=0;i<7;i++){
        if(si[i].totalGPA==7.5){
            fputs("ID: ",f2);fprintf(f2,"%d",si[i].ID);fputs(" ; ",f2);
            fputs("Name: ",f2);fprintf(f2,"%s",si[i].name);fputs("\n",f2);
        }
    }fclose(f2);
    FILE *f3,*f4;
    if(((f3=fopen("ssc_gpa_analysis.txt","w"))==NULL)||(((f4=fopen("hsc_gpa_analysis.txt","w")))==NULL)){exit(1);}
    fputs("\nFor Bangla Medium:",f3);
    fputs("\n",f3);
    fputs("===================\n",f3);
    fputs("SSC GPA: ",f3);fprintf(f3,"%f",5.00);
    fputs("\n",f3);
    fputs("===================\n",f3);
    for(int i=0;i<7;i++){
        if(si[i].ssc==5.00){
            fputs("ID: ",f3);fprintf(f3,"%d",si[i].ID);fputs(" ; ",f3);
            fputs("Name: ",f3);fprintf(f3,"%s",si[i].name);fputs("\n",f3);
        }
    }
    fputs("SSC GPA: ",f3);fprintf(f3,"%f",4.55);
    fputs("\n",f3);
    fputs("===================\n",f3);
    for(int i=0;i<7;i++){
        if(si[i].ssc==4.55){
            fputs("ID: ",f3);fprintf(f3,"%d",si[i].ID);fputs(" ; ",f3);
            fputs("Name: ",f3);fprintf(f3,"%s",si[i].name);fputs("\n",f3);
        }
    }
    fputs("\nFor English Medium:",f3);
    fputs("\n",f3);
    fputs("===================\n",f2);
    fputs("O level GPA: ",f3);fprintf(f3,"%f",4.0);
    fputs("\n",f3);
    fputs("===================\n",f3);
    for(int i=0;i<7;i++){
        if(si[i].ssc==4.0){
            fputs("ID: ",f3);fprintf(f3,"%d",si[i].ID);fputs(" ; ",f3);
            fputs("Name: ",f3);fprintf(f3,"%s",si[i].name);fputs("\n",f3);
        }
    }
    fprintf(f3,"O level GPA: %.2lf",3.5);
    fputs("\n",f3);
    fputs("===================\n",f3);
    for(int i=0;i<7;i++){
        if(si[i].ssc==3.5){
            fputs("ID: ",f3);fprintf(f3,"%d",si[i].ID);fputs(" ; ",f3);
            fputs("Name: ",f3);fprintf(f3,"%s",si[i].name);fputs("\n",f3);
        }
    }fclose(f3);
    fputs("\nFor Bangla Medium:",f4);
    fputs("\n",f4);
    fputs("===================\n",f4);
    fputs("HSC GPA: ",f4);fprintf(f4,"%f",5.00);
    fputs("\n",f4);
    fputs("===================\n",f4);
    for(int i=0;i<7;i++){
        if(si[i].hsc==5.00){
            fputs("ID: ",f4);fprintf(f4,"%d",si[i].ID);fputs(" ; ",f4);
            fputs("Name: ",f4);fprintf(f4,"%s",si[i].name);fputs("\n",f4);
        }
    }
    fputs("HSC GPA: ",f4);fprintf(f4,"%f",4.67);
    fputs("\n",f4);
    fputs("===================\n",f4);
    for(int i=0;i<7;i++){
        if(si[i].hsc==4.67){
            fputs("ID: ",f4);fprintf(f4,"%d",si[i].ID);fputs(" ; ",f4);
            fputs("Name: ",f4);fprintf(f4,"%s",si[i].name);fputs("\n",f4);
        }
    }
    fputs("HSC GPA: ",f4);fprintf(f4,"%f",4.55);
    fputs("\n",f4);
    fputs("===================\n",f4);
    for(int i=0;i<7;i++){
        if(si[i].hsc==4.55){
            fputs("ID: ",f4);fprintf(f4,"%d",si[i].ID);fputs(" ; ",f4);
            fputs("Name: ",f4);fprintf(f4,"%s",si[i].name);fputs("\n",f4);
        }
    }
    fputs("\nFor English Medium:",f4);
    fputs("\n",f4);
    fputs("===================\n",f4);
    fprintf(f4,"A level GPA: %.2lf",4.0);
    fputs("\n",f4);
    fputs("===================\n",f4);
    for(int i=0;i<7;i++){
        if(si[i].hsc==4.0){
            fputs("ID: ",f4);fprintf(f4,"%d",si[i].ID);fputs(" ; ",f4);
            fputs("Name: ",f4);fprintf(f4,"%s",si[i].name);fputs("\n",f4);
        }
    }
    fprintf(f4,"A level GPA: %.2lf",3.5);
    fputs("\n",f4);
    fputs("===================\n",f4);
    for(int i=0;i<7;i++){
        if(si[i].hsc==3.5){
            fputs("ID: ",f4);fprintf(f4,"%d",si[i].ID);fputs(" ; ",f4);
            fputs("Name: ",f4);fprintf(f4,"%s",si[i].name);fputs("\n",f4);
        }
    }fclose(f4);
}
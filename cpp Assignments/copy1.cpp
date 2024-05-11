#include<bits/stdc++.h>
#include<string.h>
using namespace std;
class student{
    public:
    char n[1000],mail[1000];
    double cgpa;
    int password,id;
    student(){}
};
class teacher{
    public:
    char n[1000],mail[1000],designation[1000];
    int password;
    teacher(){}
};
int main(void){
    int a,b,o=1;
      cout<<"How many Students: "<<endl;cin>>a;
      cout<<"How many teachers: "<<endl;cin>>b;
      student students[a];
      teacher teachers[b];
      fflush(stdin);
      cout<<"Enter Student Information: "<<endl;
      for(int i=0;i<a;i++){
          cout<<"Name: ";gets(students[i].n);fflush(stdin);
          cout<<"E-mail: ";cin>>students[i].mail;fflush(stdin);
          cout<<"CGPA: ";cin>>students[i].cgpa;fflush(stdin);
          cout<<"Password: ";cin>>students[i].password;fflush(stdin);
          students[i].id=o;o++;
      }fflush(stdin);
      cout<<"Enter Teacher Information: "<<endl;
      for(int i=0;i<b;i++){
          cout<<"Name: ";gets(teachers[i].n);fflush(stdin);
          cout<<"E-mail: ";cin>>teachers[i].mail;fflush(stdin);
          cout<<"Designation: ";cin>>teachers[i].designation;fflush(stdin);
          cout<<"password: ";cin>>teachers[i].password;fflush(stdin);
      }
      for(;;){
          int q;
          cout<<"Login as: 1. Student 2. Teacher "<<endl;cin>>q;fflush(stdin);
          if(q==1){
               char email[1000];int pass,t;
               cout<<"E-mail: ";cin>>email;cout<<"Password: ";cin>>pass;
               for(int j=0;j<a;j++){
                   if((strcmp(email,students[j].mail)==0)&&(pass==students[j].password)){
                           cout<<"login successful !"<<endl;t=j;break;
                   }
               }
               for(;;){
                    int x;
                    cout<<"Options: 1.see details 2.Edit name 3.Edit password 4.Logout 5.Exit "<<endl;cin>>x;
                    if(x==1){
                          cout<<students[t].id<<endl;
                          cout<<students[t].n<<endl;
                          cout<<students[t].mail<<endl;
                          cout<<students[t].password<<endl;
                          cout<<students[t].cgpa<<endl;
                    }
                    else if(x==2){
                        cout<<"Enter New Name: "<<endl;
                        cin>>students[t].n;
                    }
                    else if(x==3){
                        cout<<"Enter New Password: "<<endl;
                        cin>>students[t].password;
                    }
                    else if(x==4){break;}
                    else if(x==5){goto exit;}
               }
          }
          else if(q==2){
              char email[1000];int pass,t;
               cout<<"E-mail: ";cin>>email;cout<<"Password: ";cin>>pass;
               for(int j=0;j<b;j++){
                   if((strcmp(email,teachers[j].mail)==0)&&(pass==teachers[j].password)){
                           cout<<"login successful !"<<endl;t=j;break;
                   }
               }
               for(;;){
                   int z;
                   cout<<"Options: 1.See All Students 2.See All Teachers 3.Logout 4.Exit "<<endl;cin>>z;
                   if(z==1){
                       for(int c=0;c<a;c++){
                           cout<<students[c].id<<endl;
                           cout<<students[c].n<<endl;
                           cout<<students[c].mail<<endl;
                           cout<<students[c].cgpa<<endl;
                       }
                   }
                   else if(z==2){
                       for(int c=0;c<b;c++){
                           cout<<teachers[c].n<<endl;
                           cout<<teachers[c].mail<<endl;
                           cout<<teachers[c].designation<<endl;
                       }
                   }
                   else if(z==3){break;}
                   else if(z==4){goto exit;}
               }
          }
      }
      exit : ;
}
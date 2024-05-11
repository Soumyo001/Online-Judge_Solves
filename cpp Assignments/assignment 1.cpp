#include<bits/stdc++.h>
#include<string.h>
using namespace std;
class student{
    public:
    char name[1000],email[1000];
    double cgpa;
    int pass,ID;
    student(){}
};
class teacher{
    public:
    char name[1000],email[1000],designation[1000];
    int pass;
    teacher(){}
};
int main(void){
    int n,m,mo=1;
      cout<<"How many Students: "<<endl;cin>>n;
      cout<<"How many teachers: "<<endl;cin>>m;
      student students[n];
      teacher teachers[m];
      fflush(stdin);
      cout<<"Enter Student Information: "<<endl;
      for(int i=0;i<n;i++){
          cout<<"Name: ";gets(students[i].name);fflush(stdin);
          cout<<"E-mail: ";cin>>students[i].email;fflush(stdin);
          cout<<"CGPA: ";cin>>students[i].cgpa;fflush(stdin);
          cout<<"Password: ";cin>>students[i].pass;fflush(stdin);
          students[i].ID=mo;mo++;
      }fflush(stdin);
      cout<<"Enter Teacher Information: "<<endl;
      for(int i=0;i<m;i++){fflush(stdin);
          cout<<"Name: ";gets(teachers[i].name);fflush(stdin);
          cout<<"E-mail: ";cin>>teachers[i].email;fflush(stdin);
          cout<<"Designation: ";cin>>teachers[i].designation;fflush(stdin);
          cout<<"password: ";cin>>teachers[i].pass;fflush(stdin);
      }
      for(;;){
          start : ;
          int k;
          cout<<"Login as: 1. Student 2. Teacher "<<endl;cin>>k;fflush(stdin);
          if(k==1){
               char email[1000];int password,t;
               cout<<"E-mail: ";cin>>email;cout<<"Password: ";cin>>password;
               for(int j=0;j<n;j++){
                   if((strcmp(email,students[j].email)==0)&&(password==students[j].pass)){
                           cout<<"login successful !"<<endl;t=j;break;
                   }
                   else cout<<"Login Failed !"<<endl;
               }
               for(;;){
                    int x;
                    cout<<"Options: 1.see details 2.Edit name 3.Edit password 4.Logout 5.Exit "<<endl;cin>>x;
                    if(x==1){
                          cout<<students[t].ID<<endl;
                          cout<<students[t].name<<endl;
                          cout<<students[t].email<<endl;
                          cout<<students[t].pass<<endl;
                          cout<<students[t].cgpa<<endl;
                    }
                    else if(x==2){
                        cout<<"Enter New Name: "<<endl;
                        cin>>students[t].name;
                    }
                    else if(x==3){
                        cout<<"Enter New Password: "<<endl;
                        cin>>students[t].pass;
                    }
                    else if(x==4){goto start;}
                    else if(x==5){goto exit;}
               }
          }
          else if(k==2){
              char email[1000];int password,t;
               cout<<"E-mail: ";cin>>email;cout<<"Password: ";cin>>password;
               for(int j=0;j<m;j++){
                   if((strcmp(email,teachers[j].email)==0)&&(password==teachers[j].pass)){
                           cout<<"login successful !"<<endl;t=j;break;
                   }
                   else cout<<"Login Failed !"<<endl;
               }
               for(;;){
                   int z;
                   cout<<"Options: 1.See All Students 2.See All Teachers 3.Logout 4.Exit "<<endl;cin>>z;
                   if(z==1){
                       for(int c=0;c<n;c++){
                           cout<<students[c].ID<<endl;
                           cout<<students[c].name<<endl;
                           cout<<students[c].email<<endl;
                           cout<<students[c].cgpa<<endl;
                       }
                   }
                   else if(z==2){
                       for(int c=0;c<m;c++){
                           cout<<teachers[c].name<<endl;
                           cout<<teachers[c].email<<endl;
                           cout<<teachers[c].designation<<endl;
                       }
                   }
                   else if(z==3){goto start;}
                   else if(z==4){goto exit;}
               }
          }
      }
      exit : ;
}
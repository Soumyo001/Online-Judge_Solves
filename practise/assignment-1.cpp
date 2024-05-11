#include<iostream>
using namespace std;
struct DateOfBirth{
    int day,month,year;
    DateOfBirth(){}
    DateOfBirth(int _day,int _month,int _year){
        day=_day;
        month=_month;
        year=_year;
    }
    void ageBasedOnBirth(){
        cout<<(2023-year)<<endl;
    }
    void displayDOB(){
        cout<<day<<"/"<<month<<"/"<<year<<endl;
    }
};
class Student{
private:
    string name,gender;
    int age;
    int id;
    int numberOfCourses=0;
    float GPA=0.0;
    string arr[1005];
    struct DateOfBirth* birth;
public:
    Student(string _name,int _id,string _gender,int _age,int _courses,int date,int month,int year){
        name=_name;
        id=_id;
        gender=_gender;
        age=_age;
        numberOfCourses=_courses;
        birth=new DateOfBirth(date,month,year);
    }
    Student(){}
    void setName(string _name){
        name=_name;
    }
    void setGender(string _gender){
        gender=_gender;
    }
    void setId(int _id){
        id=_id;
    }    
    void setAge(int _age){
        age=_age;
    }
    void setCourse(int _courses){
        numberOfCourses=_courses;
    }
    void inputGrade(){
        for(int i=0;i<numberOfCourses;i++) cin>>arr[i];
    }
    void gpaCalculator(){
        float sum=0;
        for(int i=0;i<numberOfCourses;i++){
            if(arr[i]=="A+" || arr[i]=="a+") sum+=4.0;
            else if(arr[i]=="A" || arr[i]=="a") sum+=3.7;
            else if(arr[i]=="A-" || arr[i]=="a-") sum+=3.7;
            else if(arr[i]=="B+" || arr[i]=="b+") sum+=3.3;
            else if(arr[i]=="B" || arr[i]=="b") sum+=3.0;
            else if(arr[i]=="B-" || arr[i]=="b-") sum+=2.7;
            else if(arr[i]=="C+" || arr[i]=="c+") sum+=2.3;
            else if(arr[i]=="C" || arr[i]=="c") sum+=2.0;
            else if(arr[i]=="C-" || arr[i]=="c-") sum+=1.7;
            else if(arr[i]=="D+" || arr[i]=="d+") sum+=1.3;
            else if(arr[i]=="D" || arr[i]=="d") sum+=1.0;
            else if(arr[i]=="E" || arr[i]=="e" || arr[i]=="F" || arr[i]=="f") sum+=0.0;
        }
        cout<<"GPA :"<<(sum/numberOfCourses)<<endl;
    }
    void isLegal(){
        if(age>=18) cout<<"Legal :Yes"<<endl;
        else cout<<"Legal :No"<<endl;
    }
    void display(){
        cout<<"Name :"<<name<<endl
        <<"Roll No :"<<id<<endl
        <<"Gender :"<<gender<<endl
        <<"Age :"<<age<<endl
        <<"Grades : ";
        for(int i=0;i<numberOfCourses;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        gpaCalculator();
        isLegal();
        cout<<"Date of Birth : ";
        birth->displayDOB();
    }
};
int main(void){
    int studentNo;
    cout<<"Enter number of students you want to input :";
    cin>>studentNo;
    Student s[studentNo];
    for(int i=0;i<studentNo;i++){
        string name,gender;
        int age,id,numberOfCourses,date,month,year;
        cout<<"Enter student "<<(i+1)<<" name :";
        cin>>name;
        cout<<"Enter student "<<(i+1)<<" id :";
        cin>>id;
        cout<<"Enter student "<<(i+1)<<" age :";
        cin>>age;
        cout<<"Enter student "<<(i+1)<<" gender :";
        cin>>gender;
        cout<<"Enter student "<<(i+1)<<" number of courses :";
        cin>>numberOfCourses;
        cout<<"Enter student "<<(i+1)<<" Birth date :";
        cin>>date;
        cout<<"Enter student "<<(i+1)<<" Birth month :";
        cin>>month;
        cout<<"Enter student "<<(i+1)<<" Birth year :";
        cin>>year;
        if(date>31 || month>12){
            cout<<"Invalid date or month"<<endl;
            continue;
        }
        s[i]=Student(name,id,gender,age,numberOfCourses,date,month,year);
        cout<<"Enter student "<<(i+1)<<" Grade points (totoal ("<<numberOfCourses<<") grades:";
        s[i].inputGrade();
    }
    cout<<endl;
    for(int i=0;i<studentNo;i++){
        cout<<"Details for student "<<(i+1)<<endl<<endl;
        s[i].display();
        cout<<endl;
    }
}
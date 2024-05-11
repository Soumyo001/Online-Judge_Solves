#include<bits/stdc++.h>
#include<string.h>

using namespace std;

void push(char);
char pop();
void display();
int isoperand(char);


char s[25]={'\0'};
int top = -1;
char ch;

int main()
{

    char postfix[25] = {'\0'};
    char ele;
    int i,j;

    cout<<"\n enter postfix expression:"<<endl;

  cin>>"%s",postfix;

   cout<<"\n postfix expression= "<<s<<endl;

    i=0;

    while(i< strlen(postfix))
    {
        else = postfix[i];

        if(isoperand(ele))
        {
            push(ele);
            push(' ');
            cout<<"\n ele = %c Push to stack s",ele<<endl;
        }

        else
        {
            printf("\n operator = %c",ele);

            for(j=top-1; j>=0;j--)
            {
                if(s[j]==' ')
                {
                        s[j] = ele;
                        break;
                }
            }

        }

        display();
    cout<<"\n--------------------";

        i++;
    }

    cout<<"/n infix expression =%s",s<<endl;
}

int isoperand(char ele)
{
    if((ele>='A' && ele<='Z') || (ele>='a' && ele<='z'))

        return 1;
    else
        return 0;
}


void push(char ele)
{
    if(top==24)

       cout<<"\n Stack is full"<<endl;

    else
    {
        top++;
        s[top]=ele;
    }

}


char pop()
{
    if(top==-1)

      cout<<"\nStack is empty"<<endl;

      else
      {
          ch = s[top];
          top--;
      }

      return ch;
}


void display()
{
    int i;

    for(i=0; i<=top; i++)

       cout<<"s[%d] = %c",i,s[i]<<endl;
}

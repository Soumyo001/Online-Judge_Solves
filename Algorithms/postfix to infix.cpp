#include<bits/stdc++.h>
using namespace std;
string postfixtoinfix(string s){
    stack<string>st;
    for(int i=0;i<s.length();i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && (s[i]<='9'))){
            string x="";
            x+=s[i];
            st.push(x);
        }
        else{
            string a=st.top();st.pop();
            string b=st.top();st.pop();
            st.push("("+b+s[i]+a+")");
        }
    }
    return st.top();
}
int infixevaluation(string infix)
{
    stack<char>opt;
    stack<int>opnd;
    auto ct=[&](char c)->int{
        if(c=='^') return 3;
        else if(c=='*' || c=='/') return 2;
        else if(c=='+' || c=='-') return 1;
        else return -1;
    };
    for(int i=0; i<infix.length(); i++)
    {
        if(infix[i]=='(')
        {
            opt.push(infix[i]);
        }
        else if(infix[i]>='0' && infix[i]<='9')
        {
            opnd.push(infix[i]-'0');
        }
        else if(infix[i]==')')
        {
            while(opt.top()!='(')
            {
                char c=opt.top();
                opt.pop();
                int a=opnd.top();
                opnd.pop();
                int b=opnd.top();
                opnd.pop();
                switch(c)
                {
                case '^':
                    opnd.push(pow(b,a));
                    break;
                case '*':
                    opnd.push(b*a);
                    break;
                case '/':
                    opnd.push(b/a);
                    break;
                case '+':
                    opnd.push(b+a);
                    break;
                case '-':
                    opnd.push(b-a);
                    break;
                }
            }
            opt.pop();
        }
        else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/' || infix[i]=='^')
        {
            while(!opt.empty() && ct(infix[i])<=ct(opt.top()))
            {
                char c=opt.top();
                opt.pop();
                int a=opnd.top();
                opnd.pop();
                int b=opnd.top();
                opnd.pop();
                switch(c)
                {
                case '^':
                    opnd.push(pow(b,a));
                    break;
                case '*':
                    opnd.push(b*a);
                    break;
                case '/':
                    opnd.push(b/a);
                    break;
                case '+':
                    opnd.push(b+a);
                    break;
                case '-':
                    opnd.push(b-a);
                    break;
                }
            }
            opt.push(infix[i]);
        }
    }
    while(!opt.empty())
    {
        char c=opt.top();
        opt.pop();
        int a=opnd.top();
        opnd.pop();
        int b=opnd.top();
        opnd.pop();
        switch(c)
        {
        case '^':
            opnd.push(pow(b,a));
            break;
        case '*':
            opnd.push(b*a);
            break;
        case '/':
            opnd.push(b/a);
            break;
        case '+':
            opnd.push(b+a);
            break;
        case '-':
            opnd.push(b-a);
            break;
        }
    }
    return opnd.top();
}
int postfixEvaluation(string s){
    stack<int>st;
    for(int i=0;i<s.length();i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
            st.push(s[i]-'0');
        }else{
            int op2=st.top();st.pop();
            int op1=st.top();st.pop();
            if(s[i]=='+')
                st.push(op1 + op2);
            else if(s[i]=='-')
                st.push(op1 - op2);
            else if(s[i]=='*')
                st.push(op1 * op2);
            else if(s[i]=='/')
                st.push(op1 / op2);
            else if(s[i]=='^')
                st.push(pow(op1,op2));
        }
    }
    return st.top();
}
int main(void){
    string s;cin>>s;
    cout<<postfixtoinfix(s)<<endl;
    cout<<postfixEvaluation(s)<<" "<<infixevaluation(postfixtoinfix(s))<<endl;
}
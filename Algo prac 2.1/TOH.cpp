#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val=val;
        left=right=NULL;
    }
};
void TOH(int n,char a,char b,char c){
    if(n>0){
        TOH(n-1,a,c,b);
        cout<<a<<" -> "<<c<<endl;
        TOH(n-1,b,a,c);
    }
}
int main(void){
    int n;cin>>n;
    TOH(n,'A','B','C');
}
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        next=NULL;
    }
};
Node* head;
void push_b(int key){
    Node* p=new Node(key);
    if(head==NULL){
        head=p;
        return ;
    }
    Node* temp=head;
    while(temp->next!=NULL) temp=temp->next;
    temp->next=p;
}
void push_f(int key){
    Node* p=new Node(key);
    if(head==NULL){
        head=p;return;
    }
    p->next=head;
    head=p;
}
void rev_print(Node* node){
    if(node==NULL) return;
    rev_print(node->next);
    cout<<node->val<<" ";
}
int Count(Node* node){
    static int ct=0;
    if(node==NULL) return ct;
    ct++;
    return Count(node->next);
}
void print(Node* node){
    if(node==NULL) return;
    cout<<node->val<<" ";
    print(node->next);
}
void rev_sprint(){
    stack<int>s;
    Node* temp=head;
    while(temp!=NULL){
        s.push(temp->val);temp=temp->next;
    }
    temp=head;
    while(!s.empty()){
        temp->val=s.top();s.pop();
        temp=temp->next;
    }
    rev_print(head);
}
int mid_v(){
    int size=Count(head);
    int mid;
    if(size&1) mid=(size+1)/2;
    else mid=size/2,mid++;
    int idx=0;
    Node* temp=head;
    while(temp!=NULL){
        idx++;
        if(idx==mid) return temp->val;
        temp=temp->next;
    }
    return -1;
}
int main(void){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        push_b(x);
    }
    cout<<mid_v()<<endl;
    rev_print(head);cout<<endl;
    rev_sprint();cout<<endl;
    print(head);
}
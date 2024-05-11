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
int Count(Node* node){
    static int ct=0;
    if(node==NULL) return ct;
    ct++;
    return Count(node->next);
}
void k_rotate(int k){
    int size=Count(head);
    int idx=size-k;
    int ct=0;
    Node* temp=head;
    Node* hold=NULL;
    while(temp->next!=NULL){
        ct++;
        if(ct==idx) hold=temp;
        temp=temp->next;
    }
    temp->next=head;
    head=hold->next;
    hold->next=NULL;
}
void print(Node* node){
    if(node==NULL) return;
    cout<<node->val<<" ";
    print(node->next);
}
int main(void){
    int n,k;cin>>n>>k;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        push_b(x);
    }
    print(head);cout<<endl;
    k_rotate(k);
    print(head);cout<<endl;

}
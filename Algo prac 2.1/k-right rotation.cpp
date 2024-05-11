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
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL) temp=temp->next;
    temp->next=p;
}
void push_f(int key){
    Node* p=new Node(key);
    if(head==NULL){
        head=p;
        return;
    }
    p->next=head;
    head=p;
}
int Count(Node* node,int ct=0){
    if(node==NULL) return ct;
    return Count(node->next,ct+1);
}
void print(Node* node){
    if(node==NULL) return;
    cout<<node->val<<" ";
    print(node->next);
}
void k_rrotation(int k){
    int size=Count(head);
    int idx=abs(size-k);
    //cout<<size<<" "<<idx<<endl;
    Node* temp=head;
    Node* hold=NULL;
    int ct=0;
    while(temp->next!=NULL){
        ct++;
        if(ct==idx) hold=temp;
        temp=temp->next;
    }
    if(hold!=NULL){
        temp->next=head;
        head=hold->next;
        hold->next=NULL;
    }
}
int main(void){
    int n,k;cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        push_b(x);
    }
    while(true){
        cin>>k;
        if(k==-1) break;
        print(head);cout<<endl;
        k_rrotation(k);
        print(head);cout<<endl;
    }
}
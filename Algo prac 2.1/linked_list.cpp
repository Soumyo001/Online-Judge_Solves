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
void print(){
    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
        cnt++;
    }
    cout<<endl<<"Total "<<cnt<<" values"<<endl;
}
void rev_print(Node* node){
    if(node==NULL) return;
    rev_print(node->next);
    cout<<node->val<<" ";
}
void insert_bval(int bval,int val){
    Node* p=new Node(val);
    Node* curr_node=head;
    Node* prev_node=NULL;
    while(curr_node!=NULL){
        if(curr_node->val==bval){
            if(prev_node==NULL){
                p->next=curr_node;
                head=p;
                return;
            }
            prev_node->next=p;
            p->next=curr_node;
        }
        prev_node=curr_node;
        curr_node=curr_node->next;
    }
}
void insert_bval01(int bval,int val){
    Node* p=new Node(val);
    Node* temp=head;
    if(temp->val==bval){
        p->next=temp;
        head=p;
        return;
    }
    while(temp->next!=NULL){
        if(temp->next->val==bval){
            p->next=temp->next;
            temp->next=p;
            return;
        }
        temp=temp->next;
    }
}
void insert_aval(int aval,int val){
    Node* p=new Node(val);
    Node* curr_node=head;
    Node* prev_node=NULL;
    while(curr_node!=NULL){
        if(prev_node!=NULL && prev_node->val==aval){
            prev_node->next=p;
            p->next=curr_node;
            return;
        }
        prev_node=curr_node;
        curr_node=curr_node->next;
    }
    if(prev_node->val==aval){
        prev_node->next=p;
        p->next=NULL;
    }
}
void remove(int key){
    Node* curr_node=head;
    Node* prev_node=NULL;
    while(curr_node!=NULL){
        if(curr_node->val==key){
            if(prev_node==NULL){
                head=head->next;
                return;
            }
            prev_node->next=curr_node->next;
        }
        prev_node=curr_node;
        curr_node=curr_node->next;
    }
}
int main(void){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        if((rand()%2)==1) push_b(x);
        else push_f(x);
    }
    print();
    insert_bval(44,30);
    insert_bval(30,32);
    insert_bval(65,31);
    insert_bval(1,2);
    insert_bval(12,60);
    print();
    insert_aval(32,90);
    insert_aval(44,91);
    insert_aval(11,0);
    insert_aval(1,90);
    insert_aval(12,99);
    insert_aval(32,13);
    print();
    rev_print(head);cout<<endl;
    remove(32);
    //remove(90);
    remove(91);
    remove(30);
    print();
    rev_print(head);
}
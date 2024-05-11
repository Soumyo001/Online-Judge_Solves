#include<bits/stdc++.h>
using namespace std;
struct Node{
   int val;
   Node* right;
   Node* left;
   Node(int val){
    this->val=val;
    right=NULL;
    left=NULL;
   }
};
int search(int* in_order,int start,int end,int curr){
    if(in_order[start]==curr) return start;
    if(start>end) return -1;
    return search(in_order,start+1,end,curr);
}
Node* __pre_in_order_treeBuild(int pre_order[],int in_order[],int start,int end){
    static int idx=0;
    if(start>end) return NULL;
    int curr=pre_order[idx];idx++;
    Node* p=new Node(curr);
    if(start==end) return p;
    int pos=search(in_order,start,end,curr);
    p->left=__pre_in_order_treeBuild(pre_order,in_order,start,pos-1);
    p->right=__pre_in_order_treeBuild(pre_order,in_order,pos+1,end);
    return p;
}
void right_side_view(Node* root){
    if(root==NULL) return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=1;i<=n;i++){
            Node* p=q.front();
            q.pop();
            if(i==n) cout<<p->val<<" ";
            if(p->left!=NULL) q.push(p->left);
            if(p->right!=NULL) q.push(p->right);
        }
        cout<<endl;
    }
}
void alter_right_side_view(Node* root){
    queue<Node*>q;
    q.push(root);
    int n=q.size();
    q.push(NULL);
    int i=1;
    while(!q.empty()){
        Node* p=q.front();q.pop();
        if(p!=NULL){
            if(i==n) cout<<p->val<<" ";
            if(p->left!=NULL) q.push(p->left);
            if(p->right!=NULL) q.push(p->right);
            i++;
        }else if(!q.empty()){
            n=q.size();
            q.push(NULL);
            i=1;
        }
    }
}
void inorderPrint(Node* root){
    if(root==NULL) return;
    inorderPrint(root->left);
    cout<<root->val<<" ";
    inorderPrint(root->right);
}
int main(void){
    int pre_order[]={1,2,3,4,5,6,7,8,9,10};
    int in_order[]={4,3,5,2,7,6,8,1,10,9};
    int pre_order1[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23};
    int in_order1[]={4,3,5,2,7,6,8,1,13,12,14,11,16,15,10,18,20,19,17,22,21,23,9};
    Node* n=__pre_in_order_treeBuild(pre_order1,in_order1,0,sizeof(pre_order1)/sizeof(pre_order1[0])-1);
    inorderPrint(n);
    cout<<endl;
    right_side_view(n);
    alter_right_side_view(n);
}
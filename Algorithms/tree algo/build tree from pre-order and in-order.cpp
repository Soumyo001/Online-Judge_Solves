#include<bits/stdc++.h>
using namespace std;
struct node{
   int val;
   node* left,*right;
   node(int val){
    this->val=val;
    left=NULL;
    right=NULL;
   }
};
int search(int in_order[],int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(in_order[i]==curr) return i;
    }
    return -1;
}
node* buildTree(int pre_order[],int in_order[],int start,int end){
    static int idx=0;
    if(start>end) return NULL;
    int curr=pre_order[idx];
    idx++;
    node* p=new node(curr);
    if(start==end) return p;
    int pos=search(in_order,start,end,curr);
    p->left=buildTree(pre_order,in_order,start,pos-1);
    p->right=buildTree(pre_order,in_order,pos+1,end);
    return p;
}
void in_orderPrint(node* node){
    if(node==NULL) return;
    in_orderPrint(node->left);
    cout<<node->val<<" ";
    in_orderPrint(node->right);
}
node* buildTree1(int post_order[],int in_order[],int start,int end){
    static int idx=end;
    if(start>end) return NULL;
    int curr=post_order[idx];
    idx--;
    node *p=new node(curr);
    if(start==end) return p;
    int pos=search(in_order,start,end,curr);
    p->right=buildTree1(post_order,in_order,pos+1,end);
    p->left=buildTree1(post_order,in_order,start,pos-1);
    return p;
}
int main(void){
    int pre_order[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    int in_order[]={4,3,5,2,7,6,8,1,11,10,12,9,14,13,16,15};
    int post_order[]={4,5,3,7,8,6,2,11,12,10,14,16,15,13,9,1};
    node *n=buildTree(pre_order,in_order,0,15);
    node *p=buildTree1(post_order,in_order,0,15);
    in_orderPrint(n);
    cout<<endl;
    in_orderPrint(p);
}
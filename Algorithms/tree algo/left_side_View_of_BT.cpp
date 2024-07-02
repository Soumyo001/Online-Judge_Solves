#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* left;
    node* right;
    node(int val){
        this->val=val;
        right=left=NULL;
    }
};
int search(int in_order[],int start,int end,int curr){
    for(int i=start;i<=end;i++) if(in_order[i]==curr) return i;
    return -1;
}
node* __pre_in_order_treeBuild(int pre_order[],int in_order[],int start,int end){
    static int idx=0;
    if(start>end) return NULL;
    int curr=pre_order[idx];
    idx++;
    node* p=new node(curr);
    if(start==end) return p;
    int pos=search(in_order,start,end,curr);
    p->left=__pre_in_order_treeBuild(pre_order,in_order,start,pos-1);
    p->right=__pre_in_order_treeBuild(pre_order,in_order,pos+1,end);
    return p;
}
void in_orderPrint(node* root){
    if(root==NULL) return;
    in_orderPrint(root->left);
    cout<<root->val<<" ";
    in_orderPrint(root->right);
}
void left_side_view(node* root){
    if(root==NULL) return;
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=1;i<=n;i++){
            node* p=q.front();
            q.pop();
            if(i==1) cout<<p->val<<" ";
            if(p->left!=NULL) q.push(p->left);
            if(p->right!=NULL) q.push(p->right);
        }
        cout<<endl;
    }
}
void alter_left_side_view(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    bool i=true;//int i=1;
    while(!q.empty()){
        node* p=q.front();q.pop();
        if(p!=NULL){
            if(i) cout<<p->val<<" ";
            if(p->left!=NULL) q.push(p->left);
            if(p->right!=NULL) q.push(p->right);
            i=false;
        }else if(!q.empty()){
            q.push(NULL);
            i=true;
        }
    }
}
int main(void){
    int pre_order[]={1,2,3,4,5,6,7,8,9,10};
    int in_order[]={4,3,5,2,7,6,8,1,10,9};
    node* n=__pre_in_order_treeBuild(pre_order,in_order,0,sizeof(pre_order)/sizeof(pre_order[0])-1);
    in_orderPrint(n);
    cout<<endl;
    left_side_view(n);
    alter_left_side_view(n);
}
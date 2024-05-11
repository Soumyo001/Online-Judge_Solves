#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* right;
    node* left;
    node(int val){
        this->val=val;
        left=NULL;
        right=NULL;
    }
};
int search(int* in_order,int start,int end,int curr){
    if(*(in_order+start)==curr) return start;
    if(start>end) return -1;
    return search(in_order,start+1,end,curr);
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
int sum_at_k_level(node* root,int level){
    queue<node*>q;
    int k=0,sum=0;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* p=q.front();
        q.pop();
        if(p!=NULL){
            if(k==level) sum+=p->val;
            cout<<p->val<<" ";
            if(p->left!=NULL) q.push(p->left);
            if(p->right!=NULL) q.push(p->right); 
        }else if(!q.empty()){
            k++;
            q.push(NULL);
        }
    }
    cout<<endl;
    return sum;
}
int main(void){
    int pre_order[]={1,2,3,4,5,6,7,8,9,10};
    int in_order[]={4,3,2,6,5,7,1,8,10,9};
    node* n=__pre_in_order_treeBuild(pre_order,in_order,0,sizeof(pre_order)/sizeof(pre_order[0])-1);
    cout<<sum_at_k_level(n,1)<<endl;
}
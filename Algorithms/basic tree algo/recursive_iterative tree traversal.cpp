#include<bits/stdc++.h>
using namespace std;
struct node{
   int val;
   node* left;
   node* right;
   node(int val){
    this->val=val;
    left=NULL;
    right=NULL;
   }
};
struct node_holder{
    node* p;
    int i;
    node_holder(node* p,int i){
        this->p=p;
        this->i=i;
    }
    void setI(int x){
        i=x;
    }
    int getVal(){
        return p->val;
    }
    node* getLeft(){
        return p->left;
    }
    node* getRight(){
        return p->right;
    }
};
int search(int in_order[],int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(in_order[i]==curr) return i;
    }
    return -1;
}
node* __pre_in_orderTreeBuild(int pre_order[],int in_order[],int start,int end){
    static int idx=0;
    if(start>end) return NULL;
    int curr=pre_order[idx];
    idx++;
    node* p=new node(curr);
    if(start==end) return p;
    int pos=search(in_order,start,end,curr);
    p->left=__pre_in_orderTreeBuild(pre_order,in_order,start,pos-1);
    p->right=__pre_in_orderTreeBuild(pre_order,in_order,pos+1,end);
    return p;
}
void pre_order(node* root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    pre_order(root->left);
    pre_order(root->right);
}
void in_order(node* root){
    if(root==NULL) return;
    in_order(root->left);
    cout<<root->val<<" ";
    in_order(root->right);
}
void post_order(node* root){
    if(root==NULL) return;
    post_order(root->left);
    post_order(root->right);
    cout<<root->val<<" ";
}
void recursive_traversal(node* root){
    cout<<"Recursive"<<endl;
    pre_order(root);
    cout<<endl;
    in_order(root);
    cout<<endl;
    post_order(root);
    cout<<endl<<endl;
}
void pre_orderItr(node* root){
    stack<node_holder*> st;
   //node_holder *p=new node_holder(root,1);
    st.push(new node_holder(root,1));
    while(!st.empty()){
        node_holder* p=st.top();
        st.pop();
        if(p->p!=NULL){
            switch (p->i)
            {
            case 1:
            {
                p->setI(2);
                cout<<p->getVal()<<" ";
                st.push(p);
                break;
            }
            case 2:
            {
                p->setI(3);
                node_holder* left=new node_holder(p->getLeft(),1);
                st.push(p);
                st.push(left);
                break;
            }
            case 3:
            {
                node_holder* right=new node_holder(p->getRight(),1);
                st.push(right);
                break;
            }
            }
        }
    }
}
void in_oderItr(node* root){
    stack<node_holder*>st;
    st.push(new node_holder(root,1));
    while(!st.empty()){
        node_holder* p=st.top();
        st.pop();
        if(p->p!=NULL){
            switch(p->i){
                case 1:
                {
                    p->setI(2);
                    st.push(p);
                    st.push(new node_holder(p->getLeft(),1));
                    break;
                }
                case 2:
                {
                    cout<<p->getVal()<<" ";
                    p->setI(3);
                    st.push(p);
                    break;
                }
                case 3:
                {
                    st.push(new node_holder(p->getRight(),1));
                    break;
                }
            }
        }
    }
}
void post_orderItr(node* root){
    stack<node_holder*>st;
    st.push(new node_holder(root,1));
    while(!st.empty()){
        node_holder* p=st.top();
        st.pop();
        if(p->p!=NULL){
            switch(p->i){
                case 1:
                {
                    p->setI(2);
                    st.push(p);
                    st.push(new node_holder(p->getLeft(),1));
                    break;
                }
                case 2:
                {
                    p->setI(3);
                    st.push(p);
                    st.push(new node_holder(p->getRight(),1));
                    break;
                }
                case 3:
                {
                    cout<<p->getVal()<<" ";
                    break;
                }
            }
        }
    }
}
void level_orderItr(node* root){
    queue<node_holder*>q;
    q.push(new node_holder(root,1));
    //q.push(NULL);
    while(!q.empty()){
        node_holder* p=q.front();
        q.pop();
       // if(p!=NULL){
            cout<<p->getVal()<<" ";
            if((new node_holder(p->getLeft(),1))->p!=NULL) q.push(new node_holder(p->getLeft(),1));
            if((new node_holder(p->getRight(),1))->p!=NULL) q.push(new node_holder(p->getRight(),1));
        /*}else if(!q.empty()){
            q.push(NULL);cout<<endl;
        }*/
    }
}
void iterative_Traversal(node* root){
    cout<<"Iterative"<<endl;
    pre_orderItr(root);
    cout<<endl;
    in_oderItr(root);
    cout<<endl;
    post_orderItr(root);
    cout<<endl<<"Level_order"<<endl;
    level_orderItr(root);
    cout<<endl<<endl;
}
int main(void){
    int pre_order[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    int in_order[]={4,3,5,2,7,6,8,1,11,10,12,9,14,13,16,15};
    node* n=__pre_in_orderTreeBuild(pre_order,in_order,0,15);
    recursive_traversal(n);
    iterative_Traversal(n);
}
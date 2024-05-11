#include<bits/stdc++.h>
using namespace std;
const int N=1e4+7;
int graph[N][N];
int status[N];
struct node
{
    int val;
    node *next;
    node(int val){
        this->val=val;
        next=NULL;
    }
};
node *head;
bool isEmpty(){
    if(head==NULL) return true;
    else return false;
}
void push(int n){
    node *p=new node(n);
    if(isEmpty()){
        head=p;return;
    }
    p->next=head;
    head=p;
}
int pop(){
    int store=-1;
    if(isEmpty()) return store;
    else{
        store=head->val;
        head=head->next;
        return store;
    }
}
void initiStatus(int number_of_nodes){
    for(int i=1;i<=number_of_nodes;i++){
        status[i]=1;
    }
}
void inputGraph(int number_of_edges){
    int n,m;
    for(int i=1;i<=number_of_edges;i++){
        cin>>n>>m;
        graph[n][m]=1;
        graph[m][n]=1;
    }
}
void printfGraph(int number_of_nodes){
    for(int i=1;i<=number_of_nodes;i++){
        for(int j=1;j<=number_of_nodes;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}
void dfs(int source,int number_of_nodes){
    initiStatus(number_of_nodes);
    head=NULL;
    push(source);
    status[source]=2;
    while(!isEmpty()){
        int value=pop();
        cout<<value<<" ";
        status[value]=3;
        for(int i=number_of_nodes;i>=0;i--){
            if(graph[value][i]==1 && status[i]==1){
                push(i);
                status[i]=2;
            }
        }
    }
    cout<<endl;
}
int main(void){
    int node,edge,source;
    cin>>node>>edge;
    inputGraph(edge);
    cin>>source;
    dfs(source,node);
    printfGraph(node);
}
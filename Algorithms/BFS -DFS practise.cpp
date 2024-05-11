#include<bits/stdc++.h>
using namespace std;
const int N=1e4+7;
int graph[N][N];
int status[N];
int dist[N];
struct node{
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
void enqueue(int val){
    node *p=new node(val);
    if(isEmpty()){
        head=p;return;
    }
    node *temp=head;
    while(temp->next!=NULL) temp=temp->next;
    temp->next=p;
}
int dequeue(){
    int store=-1;
    if(isEmpty()) return store;
    store=head->val;
    head=head->next;
    return store;
}
void push(int val){
    node *p=new node(val);
    if(isEmpty()){
        head=p;return;
    }
    p->next=head;
    head=p;
}
int pop(){
    int store=-1;
    if(isEmpty()) return store;
    store=head->val;
    head=head->next;
    return store;
}
void inputGraph(int number_of_edges){
    int m,n;
    int weight=1;
    for(int i=1;i<=number_of_edges;i++){
            cin>>n>>m;
               graph[n][m]=weight;
               graph[m][n]=weight;
    }
}
void showGraph(int number_of_nodes){
    for(int i=1;i<=number_of_nodes;i++){
        for(int j=1;j<=number_of_nodes;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=1;i<=number_of_nodes;i++){
        cout<<"Distance of "<<i<<" is "<<dist[i]<<endl;
    }
    cout<<endl;
}
void initStatus(int number_of_nodes){
    for(int i=1;i<=number_of_nodes;i++){
        status[i]=1;
    }
}
void bfs(int source,int number_of_nodes){
    initStatus(number_of_nodes);
    head=NULL;
    enqueue(source);
    status[source]=2;
    dist[source]=0;
    while(!isEmpty()){
        int value=dequeue();
        cout<<value<<" ";
        status[value]=3;
        for(int i=1;i<=number_of_nodes;i++){
            if(graph[value][i]==1 && status[i]==1){
                int weight=graph[value][i];
                enqueue(i);
                status[i]=2;
                dist[i]=dist[value]+weight;
            }
        }
    }
    cout<<endl;
}
void dfs(int source,int number_of_nodes){
    initStatus(number_of_nodes);
    head=NULL;
    push(source);
    status[source]=2;
    dist[source]=0;
    while(!isEmpty()){
        int value=pop();
        cout<<value<<" ";
        status[value]=3;
        for(int i=number_of_nodes;i>=0;i--){
            if(graph[value][i]==1 && status[i]==1){
                int weight=graph[value][i];
                push(i);
                status[i]=2;
                dist[i]=dist[value]+weight;
            }
        }
    }
    cout<<endl;
}
int main(void){
    int edges,nodes;
    cin>>nodes>>edges;
    inputGraph(edges);
    int source;cin>>source;
    int i;
    cout<<"DFS or BFS"<<endl;cin>>i;cout<<endl;
    if(i==1){
        bfs(source,nodes);
        cout<<"The adjacent Matrix is :"<<endl;
        showGraph(nodes);
    }else if(i==2){
        dfs(source,nodes);
        cout<<"The adjacent Matrix is :"<<endl;
        showGraph(nodes);
    }else exit(0);
}
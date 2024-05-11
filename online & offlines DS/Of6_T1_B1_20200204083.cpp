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
bool isempty(){
    if(head==NULL) return true;
    return false;
}
void enqueue(int n){
    node *p=new node(n);
    if(isempty()){
        head=p;return;
    }
    node *temp=head;
    while(temp->next!=NULL) temp=temp->next;
    temp->next=p;
}
int dequeue(){
    int store=-1;
    if(isempty()) return store;
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
    for(int i=1;i<=number_of_nodes;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}
void bfs(int source_node,int number_of_nodes){
    initiStatus(number_of_nodes);
    head=NULL;
    enqueue(source_node);
    status[source_node]=2;
    dist[source_node]=0;
    while(!isempty()){
        int value=dequeue();
        cout<<value<<" ";
        status[value]=3;
        for(int i=1;i<=number_of_nodes;i++){
            if(graph[value][i]==1 && status[i]==1) {
                dist[i]=dist[value]+1;
                enqueue(i);
                status[i]=2;
            }
        }
    }
    cout<<endl;
}
int main(void){
    int nodes,edges;
    cin>>nodes>>edges;
    inputGraph(edges);
    int source;cin>>source;
    bfs(source,nodes);
    printfGraph(nodes);
}
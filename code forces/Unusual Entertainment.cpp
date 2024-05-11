#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
vector<vector<int>> graph;
vector<int> Tin,Tout;
vector<int> p;
int n, q;
struct SegmentTree
{
    vector<vector<int>> tree;
    SegmentTree(int size){
        tree.assign(size*3,{0});
        init(1,1,size);
    }
    void init(int node, int b, int e)
    {
        if (b==e){
            tree[node] = {p[b]};
            return;
        }
        int mid = (b + e) >> 1;
        int left = node << 1;
        int right = (node << 1) + 1;
        init(left, b, mid);
        init(right, mid + 1, e);
        for (auto &i : tree[left]) tree[node].push_back(i);
        for (auto &i : tree[right]) tree[node].push_back(i);
    }

};
void initCode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
void inputGraph()
{
    graph.assign(n + 1, vector<int>());
    Tin.assign(n+1,0);Tout.assign(n+1,0);
    p.assign(n+1,0);
    for (int i = 1; i <= (n - 1); i++)
    {
        int u, v;
        scanf("%d", &u);
        scanf("%d", &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}
void dfs(int vertex, int par)
{
    ++Tin[vertex];
    for (auto &i : graph[vertex]){
        if (i == par) continue;
        dfs(i, vertex);
    }
    
}
void solve()
{
    scanf("%d", &n);
    scanf("%d", &q);
    SegmentTree st(n);
    inputGraph();
    for (int i = 1; i <= n; i++) scanf("%d", p[i]);
    st.init(1,1,n);
    dfs(1, 0);
    // while (q--)
    // {
    //     int l, r, x;
    //     scanf("%d", &l);
    //     scanf("%d", &r);
    //     scanf("%d", &x);
    // }
    // printf("\n");
}
int main(void)
{
   // initCode();
    // ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    scanf("%d", &t);
    while (t--) solve();
}
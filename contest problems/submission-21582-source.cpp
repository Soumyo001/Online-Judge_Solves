#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;
const int INF = int(1e9);
struct SCC
{
	vector<vector<int> > vec;
	int index;
	vector<int> idx;
	vector<int> lowlink;
	vector<bool> onstack;
	stack<int> s;
	vector<int> sccidx;
	int scccnt;
	//lower sccidx means appear later
	void init(int n)
	{
		idx.assign(n,-1);
		index = 0;
		onstack.assign(n,0);
		lowlink.assign(n,INF);
		while(!s.empty()) s.pop();
		sccidx.assign(n,-1);
		scccnt = 0;
		vec.clear();
		vec.resize(n);
	}
	
	void addedge(int u, int v) //u -> v
	{
		vec[u].pb(v);
	}
	
	void connect(int u)
	{
		idx[u] = index;
		lowlink[u] = index;
		index++;
		s.push(u);
		onstack[u] = true;
		for(int i = 0; i < vec[u].size(); i++)
		{
			int v = vec[u][i];
			if(idx[v] == -1)
			{
				connect(v);
				lowlink[u] = min(lowlink[u], lowlink[v]);
			}
			else if(onstack[v])
			{
				lowlink[u] = min(lowlink[u], idx[v]);
			}
		}
		if(lowlink[u] == idx[u])
		{
			while(1)
			{
				int v = s.top();
				s.pop();
				onstack[v] = false;
				sccidx[v] = scccnt;
				if(v == u) break;
			}
			scccnt++;
		}
	}
	
	void tarjan()
	{
		for(int i = 0; i < vec.size(); i++)
		{
			if(idx[i] == -1)
			{
				connect(i);
			}
		}
	}
};

vi adj[100001];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	int cc = 0;
	while(t--)
	{
		int n,m,x;
		cin>>n>>m>>x;
		SCC scc;
		scc.init(n);
		x--;
		for(int i = 0; i < m; i++)
		{
			int u, v; cin>>u>>v;
			u--; v--;
			scc.addedge(u,v);
			adj[u].pb(v);
		}
		scc.tarjan();
		vi vec(n);
		for(int i = 0; i < n; i++)
		{
			vec[scc.sccidx[i]] = i;
		}
		vi dp;
		dp.assign(n,0);
		for(int i = 0; i < n; i++)
		{
			int u = vec[i];
			dp[u] = 0;
			for(int j = 0; j < adj[u].size(); j++)
			{
				int v = adj[u][j];
				if(dp[v] == 0)
				{
					dp[u] = 1;
					break;
				}
			}
		}
		cout<<"Case "<<++cc<<": ";
		if(dp[x]) cout<<"Yes\n";
		else cout<<"No\n";
		for(int i = 0; i < n; i++)
		{
			adj[i].clear();
		}
	}
}

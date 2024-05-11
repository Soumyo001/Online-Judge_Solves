#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
using namespace std;

const int N = 1e7 + 2;
int mx[N], mn[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, a, b, c, m; cin >> n >> a >> b >> c >> m;
		int x = b, id = 0, ans = 0; mx[0] = 0, mn[id] = m;
		for (int i = 1; i <= n; i++) {
			x = ((long long) x * a + c) % m;
			if (x & 1) {
				++id;
				mx[id] = x > mx[id - 1] ? x : mx[id - 1];
				mn[id] = x < mn[id - 1] ? x : mn[id - 1];
			}
			else {
				if (id) id--;
			}
			if (id) ans ^= mx[id] + mn[id];
		}
		cout << ans << '\n';
	}
    return 0;
}
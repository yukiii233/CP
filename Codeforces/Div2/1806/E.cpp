#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;
const int B = sqrt(N);

int n, q;
ll v[N], a[N];
int fa[N], cnt[N], dep[N];
ll h[N][B + 5];
int id[N];
vector<int> G[N];

void dfs(int u, int d) {
	id[u] = ++cnt[d];
	dep[u] = d;
	for (int v : G[u]) {
		dfs(v, d + 1);
	}
}
ll qry(int x, int y) {
	if (x > y) swap(x, y);
	if (x == 0 && y == 0) return 0;
	if (cnt[dep[x]] <= B && h[x][id[y]]) return h[x][id[y]];
	ll res = a[x] * a[y] + qry(fa[x], fa[y]);
	if (cnt[dep[x]] <= B) h[x][id[y]] = res;
	return res;
}

void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 2; i <= n; i++) {
		cin >> fa[i];
		G[fa[i]].push_back(i);
	}
	dfs(1, 0);
	while (q--) {
		int u, v;
		cin >> u >> v;
		cout << qry(u, v) << '\n';
	}
	return;
}

int main() {
	int T = 1;
	while (T--) {
		solve();
	}
}
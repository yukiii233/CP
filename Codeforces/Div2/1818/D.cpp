#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 2000 + 5;

int n, m;
int deg[N], stk[N], top;
bool vis[N];
vector<int> G[N];

bool dfs(int u, int fr, int rt) {
	vis[u] = 1;
	stk[++top] = u;
	for (int v : G[u]) if (v != fr && (!vis[v] || v == rt)) {
		if (v == rt) return 1;
		if (dfs(v, u, rt)) return 1;
	}
	top--;
	return 0;
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		G[i].clear();
		deg[i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		deg[u]++;
		deg[v]++;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int u = 1; u <= n; u++) if (deg[u] >= 4) {
		top = 0;
		fill(vis + 1, vis + n + 1, 0);
		if (dfs(u, u, u)) {
			map<int, int> mp;
			vector<pair<int, int> > ans;
			for (int k = 1; k <= top; k++) mp[stk[k]] = k;
			vector<int> in, out;
			for (int v : G[u]) if (v != stk[2] && v != stk[top]) {
				if (mp.count(v)) in.push_back(mp[v]);
				else out.push_back(v);
			}
			if (out.size() >= 2) {
				stk[++top] = u;
				for (int k = 1; k < top; k++) ans.push_back({stk[k], stk[k + 1]});
				ans.push_back({u, out[0]});
				ans.push_back({u, out[1]});
			} else if (out.size() == 1) {
				for (int k = 1; k < in[0]; k++) ans.push_back({stk[k], stk[k + 1]});
				ans.push_back({u, stk[in[0]]});
				ans.push_back({u, out[0]});
				ans.push_back({u, stk[top]});
			} else {
				if (in[0] > in[1]) swap(in[0], in[1]);
				ans.push_back({u, stk[in[0]]});
				ans.push_back({u, stk[in[1]]});
				for (int k = in[0]; k < in[1]; k++) ans.push_back({stk[k], stk[k + 1]});
				ans.push_back({u, stk[2]});
				ans.push_back({u, stk[top]});
			}
			cout << "YES\n";
			cout << ans.size() << '\n';
			for (auto [x, y] : ans) cout << x << ' ' << y << '\n';
			return;
		}
	}
	cout << "NO\n";
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}
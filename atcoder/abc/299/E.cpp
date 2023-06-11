#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 2000 + 5;

int n, m, k, p[N], d[N], col[N];
bool ban[N];
vector<int> G[N], to[N];
bool vis[N];

void bfs(int st, int D) {
	memset(vis, 0, sizeof vis);
	queue<pair<int, int> > q;
	q.push({st, 0});
	vis[st] = 1;
	while (!q.empty()) {
		auto [u, dep] = q.front();
		q.pop();
		if (dep == D) {
			to[st].push_back(u);
			continue;
		} else ban[u] = 1;
		for (int v : G[u]) if (!vis[v]) {
			q.push({v, dep + 1});
			vis[v] = 1;
		}
	}
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
    	int u, v;
    	cin >> u >> v;
    	G[u].push_back(v);
    	G[v].push_back(u);
    }
    cin >> k;
    for (int i = 1; i <= k; i++) {
    	cin >> p[i] >> d[i];
    	bfs(p[i], d[i]);
    }
	for (int i = 1; i <= k; i++) {
		bool pd = 0;
		for (int x : to[p[i]]) if (ban[x] != 1) {
			pd = 1;
			col[x] = 1;
		}
		if (!pd) return cout << "No\n", void();
	}
	for (int i = 1; i <= n; i++) if (!ban[i]) col[i] = 1;
	cout << "Yes\n";
	for (int i = 1; i <= n; i++) cout << col[i];
	cout << '\n';
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
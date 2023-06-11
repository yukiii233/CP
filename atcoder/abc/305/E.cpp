#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 2e5 + 5;

int n, m, k;
int d[N];
vector<int> G[N];
int dis[N];
bool vis[N];

void solve() {
	memset(dis, -1, sizeof dis);
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	priority_queue<pair<int, int> > q;
	for (int i = 1; i <= k; i++) {
		int u, h;
		scanf("%d %d", &u, &h);
		dis[u] = h;
		q.push({h, u});
	}
	while (!q.empty()) {
		int u = q.top().second;
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int v : G[u]) if (!vis[v]) {
			if (dis[u] - 1 > dis[v]) {
				dis[v] = dis[u] - 1;
				q.push({dis[v], v});
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (dis[i] != -1) cnt++;
	}
	printf("%d\n", cnt);
	for (int i = 1; i <= n; i++) {
		if (dis[i] != -1) printf("%d ", i);
	}
	puts("");
}

int main() {
	int T = 1;
	while (T--) {
		solve();
	}
	return 0;
}
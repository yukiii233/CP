#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 2e5 + 5;

int n, m;
bool vis[N];
int dis[N];
vector<pair<int, int> > G[N];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	priority_queue<pair<int, int> > q;
	ll res = 0;
	for (int i = 2; i <= n; i++) dis[i] = 0x3f3f3f3f;
	q.push({dis[1], 1});
	while (!q.empty()) {
		auto u= q.top().second;
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		res += dis[u];

		for (auto [v, w] : G[u]) if (!vis[v]) {
			if (dis[v] > w) {
				dis[v] = w;
				q.push({-dis[v], v});
			}
		}
	}
	printf("%lld\n", res);
	return 0;
}
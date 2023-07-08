#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int inf = 0x3f3f3f3f;
const int N = 1e5, M = 35;

int n, m, k, tot;
int cap[M], R[M], to[M][M];
// S = 0, T = 1, earth = 3, moon = 2
int head[N], cur[N], ecnt, d[N], s, t;
bool vis[N];
struct Edge {
    int nxt, v, flow, cap;
}e[N << 1];
void add_edge(int u, int v, int flow, int cap) {
    e[ecnt] = {head[u], v, flow, cap}; head[u] = ecnt++;
    e[ecnt] = {head[v], u, flow, 0}; head[v] = ecnt++;
}
bool bfs() {
    memset(vis, 0, sizeof vis);
    std::queue<int> q;
    q.push(s);
    vis[s] = 1;
    d[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i != -1; i = e[i].nxt) {
            int v = e[i].v;
            if (vis[v] || e[i].flow >= e[i].cap) continue;
            d[v] = d[u] + 1;
            vis[v] = 1;
            q.push(v);
        }
    }
    return vis[t];
}
int dfs(int u, int a) {
    if (u == t || !a) return a;
    int b = 0;
    int flow = 0, f;
    for (int& i = cur[u]; i != -1; i = e[i].nxt) {
        int v = e[i].v;
        if (d[u] + 1 == d[v] && (f = dfs(v, std::min(a, e[i].cap - e[i].flow))) > 0) {
            e[i].flow += f;
            e[i ^ 1].flow -= f;
            flow += f;
            a -= f;
            if (!a) break;
        }
    }
    return flow;
}
int id(int k, int d) {
	return k + (n + 2) * d;
}
void solve() {
	memset(head, -1, sizeof head);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &cap[i], &R[i]);
		for (int j = 0; j < R[i]; j++) scanf("%d", &to[i][j]), to[i][j] += 3;
	}
	s = 0, t = 1;
	add_edge(s, 3, 0, inf);
	add_edge(2, t, 0, inf);
	int ans = 0;
	for (int T = 1; ; T++) {
		for (int i = 2; i <= n + 3; i++) {
			add_edge(id(i, T - 1), id(i, T), 0, inf);
		}
		for (int i = 1; i <= m; i++) {
			add_edge(id(to[i][(T - 1) % R[i]], T - 1), id(to[i][T % R[i]], T), 0, cap[i]);
		}
		add_edge(id(2, T), t, 0, inf);
		int tot = id(n + 3, T);
		while (bfs()) {
			for (int i = 0; i <= tot; i++) cur[i] = head[i];
			ans += dfs(s, inf);
		}
		if (T > n + 3 && ans == 0) return puts("0"), void();
		if (ans >= k) return printf("%d\n", T), void();
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	solve();
	return 0;
}
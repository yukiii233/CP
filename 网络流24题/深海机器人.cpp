#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

const int inf = 1e9;
int head[N], cur[N], ecnt, dis[N], s, t, p, q, a, b, mincost;
bool vis[N];
struct Edge {
    int nxt, v, flow, cap, w;
}e[100002];
void add_edge(int u, int v, int flow, int cap, int w) {
    e[ecnt] = {head[u], v, flow, cap, w}; head[u] = ecnt++;
    e[ecnt] = {head[v], u, flow, 0, -w}; head[v] = ecnt++;
}
bool spfa(int s, int t) {
    memset(vis, 0, sizeof vis);
    std::fill(dis, dis + t + 1, inf);
    std::queue<int> q;
    q.push(s);
    dis[s] = 0;
    vis[s] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = head[u]; i != -1; i = e[i].nxt) {
            int v = e[i].v;
            if (e[i].flow < e[i].cap && dis[u] + e[i].w < dis[v]) {
                dis[v] = dis[u] + e[i].w;
                if (!vis[v]) vis[v] = 1, q.push(v);
            }
        }
    }
    return dis[t] != inf;
}
int dfs(int u, int a) {
    if (vis[u]) return 0;
    if (u == t || !a) return a;
    vis[u] = 1;
    int flow = 0, f;
    for (int& i = cur[u]; i != -1; i = e[i].nxt) {
        int v = e[i].v;
        if (dis[u] + e[i].w == dis[v] && (f = dfs(v, std::min(a, e[i].cap - e[i].flow))) > 0) {
            e[i].flow += f;
            e[i ^ 1].flow -= f;
            flow += f;
            mincost += e[i].w * f;
            a -= f;
            if (!a) break;
        }
    }
    vis[u] = 0;
    return flow;
}

int id[20][20], tot;

void solve() {
	memset(head, -1, sizeof head);
	scanf("%d %d %d %d", &a, &b, &p, &q);
	for (int i = 0; i <= p; i++) {
		for (int j = 0; j <= q; j++) {
			id[i][j] = ++tot;
		}
	}
	s = 0, t = tot + 1;
	for (int i = 0; i <= p; i++) {
		for (int j = 1; j <= q; j++) {
			int x;
			scanf("%d", &x);
			add_edge(id[i][j - 1], id[i][j], 0, 1, -x);
			add_edge(id[i][j - 1], id[i][j], 0, inf, 0);
		}
	}
	for (int j = 0; j <= q; j++) {
		for (int i = 1; i <= p; i++) {
			int x;
			scanf("%d", &x);
			add_edge(id[i - 1][j], id[i][j], 0, 1, -x);
			add_edge(id[i - 1][j], id[i][j], 0, inf, 0);
		}
	}
	for (int i = 1; i <= a; i++) {
		int k, x, y;
		scanf("%d %d %d", &k, &x, &y);
		add_edge(s, id[x][y], 0, k, 0);
	}
	for (int i = 1; i <= b; i++) {
		int k, x, y;
		scanf("%d %d %d", &k, &x, &y);
		add_edge(id[x][y], t, 0, k, 0);
	}
	while (spfa(s, t)) {
		for (int i = s; i <= t; i++) cur[i] = head[i];
		dfs(s, inf);
	}
	printf("%d\n", -mincost);
}

int main() {
	int T = 1;
	while (T--) {
		solve();
	}
	return 0;
}
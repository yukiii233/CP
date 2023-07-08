#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;
const int inf = 1e9;
int head[N], cur[N], ecnt, dis[N], s, t, n, m, mincost;
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

int a[25][55], id[25][55], tot;

void solve1() {
	memset(head, -1, sizeof head);
	ecnt = 0, mincost = 0;
	int ans = 0;
	s = 0, t = tot * 2 + 1;
	for (int i = 1; i <= m; i++) add_edge(s, id[1][i] * 2 - 1, 0, 1, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m + i - 1; j++) {
			add_edge(id[i][j] * 2 - 1, id[i][j] * 2, 0, 1, -a[i][j]);
			if (i != n) {
				add_edge(id[i][j] * 2, id[i + 1][j] * 2 - 1, 0, 1, 0);
				add_edge(id[i][j] * 2, id[i + 1][j + 1] * 2 - 1, 0, 1, 0);
			} else {
				add_edge(id[i][j] * 2, t, 0, 1, 0);
			}
		}
	}
	while (spfa(s, t)) {
		for (int i = s; i <= t; i++) cur[i] = head[i];
		ans += dfs(s, inf);
	}
	printf("%d\n", -mincost);
}
void solve2() {
	memset(head, -1, sizeof head);
	ecnt = 0, mincost = 0;
	int ans = 0;
	s = 0, t = tot * 2 + 1;
	for (int i = 1; i <= m; i++) add_edge(s, id[1][i] * 2 - 1, 0, 1, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m + i - 1; j++) {
			add_edge(id[i][j] * 2 - 1, id[i][j] * 2, 0, m, -a[i][j]);
			if (i != n) {
				add_edge(id[i][j] * 2, id[i + 1][j] * 2 - 1, 0, 1, 0);
				add_edge(id[i][j] * 2, id[i + 1][j + 1] * 2 - 1, 0, 1, 0);
			} else {
				add_edge(id[i][j] * 2, t, 0, m, 0);
			}
		}
	}
	while (spfa(s, t)) {
		for (int i = s; i <= t; i++) cur[i] = head[i];
		ans += dfs(s, inf);
	}
	printf("%d\n", -mincost);
}
void solve3() {
	memset(head, -1, sizeof head);
	ecnt = 0, mincost = 0;
	int ans = 0;
	s = 0, t = tot + 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i - 1 + m; j++) {
			if (i == 1) {
				add_edge(s, id[i][j], 0, 1, -a[i][j]);
			}
			if (i == n) {
				add_edge(id[i][j], t, 0, m, 0);
			} else {
				add_edge(id[i][j], id[i + 1][j], 0, m, -a[i + 1][j]);
				add_edge(id[i][j], id[i + 1][j + 1], 0, m, -a[i + 1][j + 1]);
			}
		}
	}
	while (spfa(s, t)) {
		for (int i = s; i <= t; i++) cur[i] = head[i];
		ans += dfs(s, inf);
	}
	printf("%d\n", -mincost);
}

int main() {
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m + i - 1; j++)
			scanf("%d", &a[i][j]), id[i][j] = ++tot;
	}
	solve1();
	solve2();
	solve3();
	return 0;
}
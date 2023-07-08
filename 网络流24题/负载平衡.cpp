#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const int N = 1e5 + 5;

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

int a[N];

void solve() {
	memset(head, -1, sizeof head);
	int avg = 0, det = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		avg += a[i];
	}
	avg /= n;
	s = 0, t = n + 1;
	for (int i = 1; i <= n; i++) {
		int nx = i + 1, ls = i - 1;
		if (nx > n) nx = 1;
		if (ls < 1) ls = n;
		add_edge(i, ls, 0, inf, 1);
		add_edge(i, nx, 0, inf, 1);
		if (a[i] > avg) {
			det += a[i] - avg;
			add_edge(s, i, 0, a[i] - avg, 0);
		} else if (a[i] < avg) {
			add_edge(i, t, 0, avg - a[i], 0);
		}
	}
	while (spfa(s, t)) {
		for (int i = s; i <= t; i++) cur[i] = head[i];
		dfs(s, inf);
	}
	printf("%d\n", mincost);
}

int main() {
	int T = 1;
	while (T--) {
		solve();
	}
	return 0;
}
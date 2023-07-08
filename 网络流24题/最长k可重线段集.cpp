#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long

const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const int N = 1e5 + 5;

int head[N], cur[N], ecnt, dis[N], s, t, n, k, mincost;
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

void solve() {
    memset(head, -1, sizeof head);
	scanf("%lld %lld", &n, &k);
	vector<int> po;
	vector<tuple<int, int, int>> v;
	for (int i = 1; i <= n; i++) {
		int x, y, x1, y1;
		scanf("%lld %lld %lld %lld", &x, &y, &x1, &y1);
		int res = sqrt((x - x1) * 1ll * (x - x1) + (y - y1) * 1ll * (y - y1));
		if (x > x1) swap(x, x1);
		if (x == x1) x *= 2, x1 = x + 1;
		else x = x * 2 + 1, x1 = x1 * 2;
		v.push_back({x, x1, res});
		po.push_back(x);
		po.push_back(x1);
	}
	sort(po.begin(), po.end());
	po.erase(unique(po.begin(), po.end()), po.end());
    for (auto &[x, y, res] : v) {
        x = lower_bound(po.begin(), po.end(), x) - po.begin() + 1;
        y = lower_bound(po.begin(), po.end(), y) - po.begin() + 1;
        add_edge(x, y, 0, 1, -res);
    }
    int m = po.size();
    s = 0, t = m + 1;
    for (int i = 0; i <= m; i++)
        add_edge(i, i + 1, 0, k, 0);
    while (spfa(s, t)) {
        for (int i = s; i <= t; i++) cur[i] = head[i];
        dfs(s, inf);
    }
    printf("%lld\n", -mincost);
}

signed main() {
	int T = 1;
	while (T--) {
		solve();
	}
	return 0;
}
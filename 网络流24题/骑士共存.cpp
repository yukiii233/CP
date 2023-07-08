#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const int N = 1e6 + 5;
int head[N], cur[N], ecnt, d[N], s, t, n, m;
bool vis[N];
struct Edge {
    int nxt, v, flow, cap;
}e[N << 1];
void add_edge(int u, int v, int flow, int cap) {
    e[ecnt] = {head[u], v, flow, cap}; head[u] = ecnt++;
    e[ecnt] = {head[v], u, flow, 0}; head[v] = ecnt++;
}
bool bfs() {
    fill(vis, vis + t + 1, 0);
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

int id[205][205];
int dx[8] = {1, -1, -2, -2, 2, 2, 1, -1};
int dy[8] = {2, 2, 1, -1, 1, -1, -2, -2};

void solve() {
	memset(head, -1, sizeof head);
	scanf("%d %d", &n, &m);
	int tot = 0;
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		id[x][y] = -1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) if (id[i][j] != -1) {
			id[i][j] = ++tot;
		}
	}
	s = 0, t = tot + 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) if (id[i][j] != -1) {
			if ((i + j) & 1) {
				add_edge(s, id[i][j], 0, 1);
				for (int k = 0; k < 8; k++) {
					int x = i + dx[k], y = j + dy[k];
					if (x > n || y > n || x < 1 || y < 1) continue;
					if (id[x][y] == -1) continue;
					add_edge(id[i][j], id[x][y], 0, inf);
				}
			} else add_edge(id[i][j], t, 0, 1);
		}
	}
	int ans = 0;
	while (bfs()) {
		for (int i = s; i <= t; i++) cur[i] = head[i];
		ans += dfs(s, inf);
	}
	printf("%d\n", tot - ans);
}

int main() {
	int T = 1;
	while (T--) {
		solve();
	}
	return 0;
}
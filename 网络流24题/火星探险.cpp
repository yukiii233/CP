#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

const int inf = 1e9;
int head[N], cur[N], ecnt, dis[N], s, t, num, n, m, mincost;
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

int mp[40][40], tot, id[40][40], line[1700];
int dx[2] = {0, 1};
int dy[2] = {1 ,0};

vector<pair<int, int> > G[N];
int stk[N], top;

bool dfs(int u) {
	//printf("* %d\n", u);
	if (u == id[n][m]) return true;
	for (auto &[v, w] : G[u]) if (w) {
		w--;
		assert(v > u);
		if (dfs(v)) {
			stk[++top] = line[u] == line[v];
			return true;
		} else w++;
	}
	return false;
}

void solve() {
	memset(head, -1, sizeof head);
	scanf("%d %d %d", &num, &m, &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &mp[i][j]);
			if (mp[i][j] == 1) id[i][j] = -1;
			else id[i][j] = ++tot, line[tot] = i;
		}
	}
	s = 0, t = tot * 2 + 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) if (id[i][j] != -1) {
			add_edge(id[i][j] * 2 - 1, id[i][j] * 2, 0, inf, 0);
			add_edge(id[i][j] * 2 - 1, id[i][j] * 2, 0, 1, -(mp[i][j] == 2));
			for (int k = 0; k < 2; k++) {
				int x = i + dx[k], y = j + dy[k];
				if (x > n || y > m || id[x][y] == -1) continue;
				add_edge(id[i][j] * 2, id[x][y] * 2 - 1, 0, inf, 0);
			}
		}
	}
	add_edge(s, id[1][1] * 2 - 1, 0, num, 0);
	add_edge(id[n][m] * 2, t, 0, inf, 0);
	int ans = 0;
	while (spfa(s, t)) {
		for (int i = s; i <= t; i++) cur[i] = head[i];
		ans += dfs(s, inf);
	}
	for (int i = 1; i < tot; i++) {
		int u = i * 2;
		for (int j = head[u]; j != -1; j = e[j].nxt) if (e[j].flow > 0 && e[j].cap != 0) {
			int v = e[j].v, w = e[j].flow;
			v = (v + 1) / 2;
			//printf("%d %d %d\n", i, v, w);
			G[i].push_back({v, w});
		}
	}
	//printf("%d\n", ans);
	for (int i = 1; i <= ans; i++) {
		dfs(id[1][1]);
		while (top) printf("%d %d\n", i, stk[top--]);
	}
}

int main() {
	int T = 1;
	while (T--) {
		solve();
	}
	return 0;
}
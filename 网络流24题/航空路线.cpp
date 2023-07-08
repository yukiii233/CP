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
int tot;
map<string, int> mp;
map<int, string> imp;
bool vvis[N];
vector<int> G[N];
void dfs(int u) {
	vvis[u] = 1;
	cout << imp[u] << '\n';
	for (int v : G[u]) if (!vvis[v]) {
		dfs(v);
	}
}

void solve() {
	memset(head, -1, sizeof head);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		mp[s] = ++tot;
		imp[tot] = s;
	}
	s = 0, t = n * 2 + 1;
	for (int i = 1; i <= m; i++) {
		string s, t;
		cin >> s >> t;
		int x = mp[s], y = mp[t];
		if (x > y) swap(x, y);
		add_edge(x * 2, y * 2 - 1, 0, 1, 0);
	}
	for (int i = 1; i <= n; i++) {
		add_edge(i * 2 - 1, i * 2, 0, 1 + (i == n || i == 1), -1);
	}
	add_edge(s, 1, 0, 2, 0);
	add_edge(n * 2, t, 0, 2, 0);
	int ans = 0;
	while (spfa(s, t)) {
		for (int i = s; i <= t; i++) cur[i] = head[i];
		ans += dfs(s, inf);
	}
	if (ans == 0) cout << "No Solution!\n";
	else {
		cout << - mincost - (ans == 2 ? 2 : 0) << '\n';
		for (int i = 2; i < n + n; i += 2) {
			for (int j = head[i]; j != -1; j = e[j].nxt) {
				if (e[j].cap == 0) continue;
				if (e[j].cap == e[j].flow) {
					//cout << e[j].v / 2 + 1 << ' ' << i / 2 << '\n';
					G[e[j].v / 2 + 1].push_back(i / 2);
					G[i / 2].push_back(e[j].v / 2 + 1);
				}
			}
		}
		dfs(1);
		cout << imp[1] << '\n';
	}
}

int main() {
	int T = 1;
	while (T--) {
		solve();
	}
	return 0;
}
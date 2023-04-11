#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
struct Edge {
    int nxt, v, flow, cap;
} e[N * N * 2];
const int INF = 0x3f3f3f3f;
int n, s, t, ecnt, head[N], cur[N], d[N];
bool vis[N];
int dp[N], a[N];

void add_edge(int u, int v, int flow, int cap) {
    e[ecnt] = {head[u], v, flow, cap}; head[u] = ecnt++;
    e[ecnt] = {head[v], u, 0, 0}; head[v] = ecnt++;
}

bool bfs() {
    memset(vis, 0, sizeof vis);
    memset(d, 0, sizeof d);
    queue<int> q;
    q.push(s);
    vis[s] = 1;
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
    if (!a || u == t) return a;
    int flow = 0, f;
    for (int &i = cur[u]; i != -1; i = e[i].nxt) {
        int v = e[i].v;
        if (d[v] == d[u] + 1 && (f = dfs(v, min(a, e[i].cap - e[i].flow))) > 0) {
            e[i].flow += f;
            e[i ^ 1].flow -= f;
            flow += f;
            a -= f;
            if (!a) break;
        }
    }
    return flow;
}

void solve() {
    memset(head, -1, sizeof head);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[j] <= a[i]) dp[i] = max(dp[j] + 1, dp[i]);
        }
    }
    int ss = 0;
    for (int i = 1; i <= n; i++) ss = max(ss, dp[i]);
    printf("%d\n", ss);
    s = 0, t = n + n + 1;
    vector<int> v[ss + 1];
    for (int i = 1; i <= n; i++) v[dp[i]].push_back(i);
    add_edge(1, 1 + n, 0, 1);
    add_edge(n, n + n, 0, 1);
    for (int i = 2; i < n; i++) {
        add_edge(i, i + n, 0, 1);
    }
    for (int k = 1; k < ss; k++) {
        for (int x : v[k]) {
            for (int y : v[k + 1]) {
                if (x <= y && a[x] <= a[y]) {
                    add_edge(x + n, y, 0, 1);
                }
            }
        }
    }
    for (int x : v[1]) add_edge(s, x, 0, 1);
    for (int x : v[ss]) add_edge(x + n, t, 0, 1);
    int ans = 0;
    while (bfs()) {
        for (int i = s; i <= t; i++) cur[i] = head[i];
        ans += dfs(s, INF);
    }
    printf("%d\n", ans);
    memset(head, -1, sizeof head);
    ecnt = 0;
    add_edge(1, 1 + n, 0, INF);
    add_edge(n, n + n, 0, INF);
    for (int i = 2; i < n; i++) {
        add_edge(i, i + n, 0, 1);
    }
    for (int k = 1; k < ss; k++) {
        for (int x : v[k]) {
            for (int y : v[k + 1]) {
                if (x <= y && a[x] <= a[y]) {
                    add_edge(x + n, y, 0, 1);
                }
            }
        }
    }
    for (int x : v[1]) add_edge(s, x, 0, INF);
    for (int x : v[ss]) add_edge(x + n, t, 0, INF);
    ans = 0;
    while (bfs()) {
        for (int i = s; i <= t; i++) cur[i] = head[i];
        ans += dfs(s, INF);
    }
    if (ss == 1) ans = n;
    printf("%d\n", ans);
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
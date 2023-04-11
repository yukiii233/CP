#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 555;
int s, t, head[N], cur[N], ecnt, n, m, r[155], c[275];

struct Edge {
    int nxt, v, flow, cap;
} e[152 * 270 * 2];

int d[N];
bool vis[N];

void add_edge(int u, int v, int flow, int cap) {
    e[ecnt] = {head[u], v, 0, cap}; head[u] = ecnt++;
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
            vis[v] = 1;
            d[v] = d[u] + 1;
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
    scanf("%d %d", &n, &m);
    s = 0, t = n + m + 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &r[i]), ans -= r[i];
    for (int i = 1; i <= m; i++) scanf("%d", &c[i]);
    for (int i = 1; i <= n; i++) add_edge(s, i, 0, r[i]);
    for (int i = n + 1; i < t; i++) add_edge(i, t, 0, c[i - n]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            add_edge(i, j + n, 0, 1);
        }
    while (bfs()) {
        for (int i = s; i <= t; i++) cur[i] = head[i];
        ans += dfs(s, 0x3f3f3f3f);
    }
    if (ans != 0) {
        puts("0");
        return;
    }
    printf("%d\n", ans ^ 1);
    for (int i = 1; i <= n; i++) {
        for (int j = head[i]; j != -1; j = e[j].nxt) {
            int k = e[j].v;
            if (e[j].flow == 1) printf("%d ", k - n);
        }
        puts("");
    }
}

int main() {
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
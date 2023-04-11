#include <bits/stdc++.h>
using namespace std;

const int N = 905;
struct Edge {
    int nxt, v, flow, cap;
} e[2 * 905 * 901];
const int INF = 0x3f3f3f3f;
int n, m, s, t, ecnt, head[N], cur[N], d[N], a[31][31];
bool vis[N];

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

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int id(int x, int y) {
    return (x - 1) * m + y;
}

void solve() {
    memset(head, -1, sizeof head);
    scanf("%d %d", &n, &m);
    s = 0, t = n * m + 1;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]), ans += a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if ((i + j) & 1) {
                add_edge(s, id(i, j), 0, a[i][j]);
            } else add_edge(id(i, j), t, 0, a[i][j]);
        }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (x >= 1 && x <= n && y >= 1 && y <= m) {
                    if ((i + j) & 1) {
                        add_edge(id(i, j), id(x, y), 0, INF);
                    } else add_edge(id(x, y), id(i, j), 0, INF);
                }
            }
        }
    }
    while (bfs()) {
        for (int i = s; i <= t; i++) cur[i] = head[i];
        ans -= dfs(s, INF);
    }
    printf("%d\n", ans);
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
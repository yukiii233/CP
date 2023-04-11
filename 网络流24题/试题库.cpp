#include <bits/stdc++.h>
using namespace std;

const int N = 1300;
struct Edge {
    int nxt, v, flow, cap;
} e[2 * 21 * 1005];
const int INF = 0x3f3f3f3f;
int n, k, s, t, ecnt, head[N], cur[N], d[N];
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

void solve() {
    memset(head, -1, sizeof head);
    scanf("%d %d", &k, &n);
    s = 0, t = n + k + 1;
    int m = 0;
    for (int i = 1; i <= k; i++) {
        int x;
        scanf("%d", &x);
        m += x;
        add_edge(s, i, 0, x);
    }
    for (int i = 1; i <= n; i++) {
        int num, x;
        scanf("%d", &num);
        while (num--) {
            scanf("%d", &x);
            add_edge(x, i + k, 0, 1);
        }
        add_edge(i + k, t, 0, 1);
    }
    int ans = 0;
    while (bfs()) {
        for (int i = s; i <= t; i++) cur[i] = head[i];
        ans += dfs(s, INF);
    }
    if (ans != m) return puts("No Solution!"), void();
    for (int i = 1; i <= k; i++) {
        printf("%d: ", i);
        for (int j = head[i]; j != -1; j = e[j].nxt) {
            int v = e[j].v;
            if (v != s && e[j].flow == e[j].cap) printf("%d ", v - k);
        }
        puts("");
    }
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
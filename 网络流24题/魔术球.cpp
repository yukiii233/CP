#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1600 * 2;
int head[N], cur[N], ecnt, d[N], n, s, t, mch[N];
bool vis[N];

struct Edge {
    int nxt, v, flow, cap;
} e[N * N * 2];
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

bool check(int x) {
    int y = sqrt(x);
    return y * y == x || (y + 1) * (y + 1) == x || (y - 1) * (y - 1) == x;
}
void print(int x, int y) {
    if (!mch[x + y]) printf("%d ", x);
    else {
        print(mch[x + y], y);
        printf("%d ", x);
    }
}

int solve(int x) {
    memset(head, -1, sizeof head);
    ecnt = 0;
    s = 0, t = x + x + 1;
    for (int i = 1; i <= x; i++) {
        for (int j = i + 1; j <= x; j++) if (check(i + j))
            add_edge(i, j + x, 0, 1);
    }
    for (int i = 1; i <= x; i++) add_edge(s, i, 0, 1);
    for (int i = x + 1; i <= x + x; i++) add_edge(i, t, 0, 1);
    int ans = x;
    while (bfs()) {
        for (int i = s; i <= t; i++) cur[i] = head[i];
        ans -= dfs(s, 0x3f3f3f3f);
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    int l = 1, r = 1599, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (solve(mid) <= n) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    solve(ans);
    printf("%d\n", ans);
    for (int u = ans + 1; u <= ans + ans; u++) {
        for (int i = head[u]; i != -1; i = e[i].nxt) {
            int v = e[i].v;
            if (v != t && e[i].flow == -1) mch[u] = v;
        }
    }
    for (int u = 1; u <= ans; u++) {
        bool pd = 1;
        for (int i = head[u]; i != -1; i = e[i].nxt) {
            int v = e[i].v;
            if (v != s && e[i].flow == 1) pd = 0;
        }
        if (pd) print(u, ans), puts("");
    }
    return 0;
}
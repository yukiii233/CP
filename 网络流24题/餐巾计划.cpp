#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int NM = 2000 + 5;
int r[NM];
int P, M, F, N, S;

int head[NM], cur[NM], ecnt, dis[NM], s, t, n, mincost;
bool vis[NM];
struct Edge {
    int nxt, v, flow, cap, w;
}e[NM * NM * 2];
void add_edge(int u, int v, int w, int flow, int cap) {
    e[ecnt] = {head[u], v, flow, cap, w}; head[u] = ecnt++;
    e[ecnt] = {head[v], u, flow, 0, -w}; head[v] = ecnt++;
}
bool spfa() {
    memset(vis, 0, sizeof vis);
    memset(dis, 0x3f, sizeof dis);
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
    return dis[t] != INF;
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

int id(int x, int tp) {
    return tp == 0 ? x : n + x; 
}

void solve() {
    memset(head, -1, sizeof head);
    scanf("%d", &n);
    scanf("%d %d %d %d %d", &P, &M, &F, &N, &S);
    for (int i = 1; i <= n; i++) scanf("%d", &r[i]);
    s = 0, t = n * 2 + 1;
    for (int i = 2; i <= n; i++) {
        add_edge(s, id(i - 1, 0), 0, 0, r[i - 1]);
        add_edge(id(i - 1, 0), id(i, 0), 0, 0, INF);
    }
    for (int i = 1; i <= n; i++) {
        add_edge(s, id(i, 1), P, 0, r[i]);
        add_edge(id(i, 1), t, 0, 0, r[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (i + M <= n) add_edge(id(i, 0), id(i + M, 1), F, 0, INF);
        if (i + N <= n) add_edge(id(i, 0), id(i + N, 1), S, 0, INF);
    }
    int ans = 0;
    while (spfa()) {
        for (int i = s; i <= t; i++) cur[i] = head[i];
        ans += dfs(s, INF);
    }
    //printf("%d\n", ans);
    printf("%d\n", mincost);
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
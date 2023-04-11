#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 105;

struct Edge {
    int nxt, v, flow, cap;
} e[N * N * 2];
int n, m, s, t, d[N], head[N], cur[N], ecnt;
int a[N];
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
    string st;
    getline(cin, st);
    stringstream ss(st);
    ss >> st;
    n = stoi(st);
    ss >> st;
    m = stoi(st);
    s = 0, t = n + m + 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        string st;
        getline(cin, st);
        stringstream ss(st);
        ss >> st;
        int x = stoi(st);
        add_edge(s, i, 0, x);
        ans += x;
        while (ss >> st) {
            int x = stoi(st);
            add_edge(i, x + n, 0, 0x3f3f3f3f);
        }
    }
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        add_edge(i + n, t, 0, x);
    }
    while (bfs()) {
        for (int i = s; i <= t; i++) cur[i] = head[i];
        ans -= dfs(s, 0x3f3f3f3f);
    }
    for (int i = 1; i <= n; i++) if (vis[i]) cout << i << ' ';
    cout << '\n';
    for (int i = n + 1; i <= n + m; i++) if (vis[i]) cout << i - n << ' ';
    cout << '\n' << ans << '\n';
}

int main() {
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
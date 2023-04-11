#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

int n, m;
ll s[N], dp[N], ans;
int q[N], ql, qr;
int stkl[N], stkr[N], topl, topr;

int head[N], ecnt;
struct Edge {
    int nxt, v, w;
} e[N << 1];

void add_edge(int u, int v, int w) {
    e[++ecnt] = {head[u], v, w}; head[u] = ecnt;
    e[++ecnt] = {head[v], u, w}; head[v] = ecnt;
}

ll x(int i) { return s[i] + s[i]; }
ll y(int i) { return dp[i] + s[i] * s[i]; }

void dfs(int u, int fa) {
    int cntl = 0, cntr = 0;
    if (u != 1) {
        while (ql < qr && y(q[ql + 1]) - y(q[ql]) <= s[u] * (x(q[ql + 1]) - x(q[ql]))) stkl[++topl] = q[ql++], cntl++;
        dp[u] = y(q[ql]) - s[u] * x(q[ql]) + s[u] * s[u] + m;
        while (ql < qr && (y(u) - y(q[qr])) * (x(q[qr]) - x(q[qr - 1])) <= 
            (x(u) - x(q[qr])) * (y(q[qr]) - y(q[qr - 1]))) stkr[++topr] = q[qr--], cntr++;
        q[++qr] = u;
    }
    for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].v, w = e[i].w;
        if (v == fa) continue;
        s[v] = s[u] + w;
        dfs(v, u);
    }
    if (u != 1) {
        --qr;
        while (cntl--) q[--ql] = stkl[topl--];
        while (cntr--) q[++qr] = stkr[topr--];
    }
    //printf("%d %lld\n", u, dp[u]);
    ans = max(ans, dp[u]);
}

void solve() {
    scanf("%d %d", &n, &m);
    topl = topr = 0;
    q[ql = qr = 0] = 1;
    ecnt = 0;
    for (int i = 1; i <= n; i++) head[i] = 0;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
    }
    ans = 0;
    dp[1] = -m;
    dfs(1, 1);
    printf("%lld\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
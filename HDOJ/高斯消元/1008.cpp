#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 5e4 + 5;

int n, m;
ll X[N], a[66];
vector<pair<int, ll> > G[N];
bool vis[N];

void insert(ll x) {
    for (int i = 60; i >= 0; i--) if ((x >> i) & 1) {
        if (!a[i]) {
            a[i] = x;
            break;
        }
        x ^= a[i];
    }
}
void dfs(int u, int fa, ll sum) {
    if (vis[u]) {
        insert(sum ^ X[u]);
        return;
    }
    vis[u] = 1;
    X[u] = sum;
    for (auto x : G[u]) {
        int v = x.first;
        ll w = x.second;
        if (v == fa) continue;
        dfs(v, u, sum ^ w);
    }
}

void solve() {
    static int Case = 0;
    printf("Case #%d: ", ++Case);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) G[i].clear(), X[i] = 0, vis[i] = 0;
    memset(a, 0, sizeof a);
    for (int i = 1; i <= m; i++) {
        int u, v;
        ll w;
        scanf("%d %d %lld", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    dfs(1, 1, 0);
    ll res = 0;
    for (int i = 60; i >= 0; i--) {
        res = max(res, a[i] ^ res);
    }
    printf("%lld\n", res);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
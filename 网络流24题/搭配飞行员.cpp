#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 105;
int n, m;
vector<int> G[N];
int mch[N], vis[N];

bool dfs(int u, int dfc) {
    for (int v : G[u]) if (vis[v] != dfc) {
        vis[v] = dfc;
        if (!mch[v] || dfs(mch[v], dfc)) return mch[v] = u, 1;
    }
    return 0;
}

void solve() {
    scanf("%d %d", &n, &m);
    int u, v;
    while (~scanf("%d %d", &u, &v)) {
        G[u].push_back(v);
    }
    int re = 0;
    for (int i = 1; i <= n - m; i++) if (dfs(i, i)) re++;
    printf("%d\n", re);
}

int main() {
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
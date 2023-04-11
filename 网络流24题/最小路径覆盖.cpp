#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 405;
int n, m;
vector<int> G[N];
int mch[N], vis[N];
bool out[N];

bool dfs(int u, int dfc) {
    for (int v : G[u]) if (vis[v] != dfc) {
        vis[v] = dfc;
        if (!mch[v] || dfs(mch[v], dfc)) return mch[v] = u, 1;
    }
    return 0;
}
void print(int x) {
    if (!mch[x + n]) printf("%d ", x);
    else {
        print(mch[x + n]);
        printf("%d ", x);
    }
}

void solve() {
    scanf("%d %d", &n, &m);
    int u, v;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v + n);
    }
    int re = 0;
    for (int i = 1; i <= n; i++) if (dfs(i, i)) re++;
    for (int i = 1; i <= n; i++) out[mch[i + n]] = 1;
    for (int i = 1; i <= n; i++) if (!out[i]) {
        print(i);
        puts("");
    }
    printf("%d\n", n - re);
}

int main() {
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
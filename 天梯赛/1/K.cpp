#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 5;
int fa[N], n, m;
bool vis[N];
int d[N];
vector<int> G[N];

void dfs(int u, int faz) {
    for (int v : G[u]) if (v != faz) {
        d[v] = d[u] + 1;
        dfs(v, u);
    }
}

void solve() {
    cin >> n >> m;
    int root = 0;
    for (int i = 1; i <= n; i++) {
        cin >> fa[i];
        if (fa[i] != -1) {
            G[fa[i]].push_back(i);
            G[i].push_back(fa[i]);
        } else root = i;
    }
    dfs(root, root);
    int mx = 0, cnt = 0;
    while (m--) {
        int x;
        cin >> x;
        mx = max(mx, d[x]);
        while (!vis[x]) {
            vis[x] = 1;
            if (x == root) break;
            cnt += 2;
            x = fa[x];
        }
        cout << cnt - mx << '\n';
    }
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
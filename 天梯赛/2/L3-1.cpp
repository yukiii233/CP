#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 500 + 5;

int n, m, S, T;
int dp[N];
bool vis[N], flag;
vector<int> G[N];

int dfs(int u) {
    if (vis[u] != 0) return dp[u];
    vis[u] = 1;
    if (G[u].empty() && u != T) flag = 1;
    for (int v : G[u]) {
        dfs(v);
        dp[u] += dp[v];
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }
    cin >> S >> T;
    dp[T] = 1;
    vis[T] = 1;
    dfs(S);
    cout << dp[S] << ' ';
    flag ? cout << "No\n" : cout << "Yes\n";
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

int n, dp[N], nxt[N], in[N];
vector<int> G[N];

void dfs(int u) {
    dp[u] = 1;
    for (int v : G[u]) {
        dfs(v);
        if (dp[v] + 1 == dp[u] && nxt[u] > v) {
            nxt[u] = v;
        } else if (dp[v] + 1 > dp[u]) {
            nxt[u]  =v;
            dp[u] = dp[v] + 1;
        }
    }
}

void solve() {
    cin >> n;
    memset(nxt, -1, sizeof nxt);
    for (int i = 0; i < n; i++) {
        int num, j;
        cin >> num;
        while (num--) {
            cin >> j;
            G[i].push_back(j);
            in[j]++;
        }
    }
    int root;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) {
            root = i;
            break;
        }
    }
    dfs(root);
    int u = root;
    cout << dp[root] << '\n';
    cout << root;
    while (nxt[u] != -1) {
        u = nxt[u];
        cout << ' ' << u;
    }
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
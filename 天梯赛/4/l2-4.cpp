#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

int n, m, num[N], p[105];
vector<int> G[N];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        G[i].push_back(233);
        for (int j = 1; j <= num[i]; j++) {
            int v;
            cin >> v;
            G[i].push_back(v);
        }
    }
    int u = 1;
    for (int i = 1; i <= m; i++) {
        int op, x;
        cin >> op >> x;
        if (op == 0) u = G[u][x];
        if (op == 1) p[x] = u, cout << u << '\n';
        if (op == 2) u = p[x];
    }
    cout << u << '\n';
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
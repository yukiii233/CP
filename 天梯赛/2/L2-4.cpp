#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 205 + 5;

int n, m, k;
int mincost = INT_MAX, ans, cnt;
int a[N][N], b[N], num, c[N];

int check() {
    int res = 0;
    memset(c, 0, sizeof c);
    int cn = 0;
    for (int i = 1; i <= n; i++) if (!c[b[i]]) {
        cn++;
        c[b[i]] = 1;
    }
    if (cn != n) return -1;
    if (a[0][b[1]] == 0) return -1;
    res += a[0][b[1]];
    for (int i = 2; i <= n; i++) {
        if (a[b[i - 1]][b[i]] == 0) return -1;
        res += a[b[i - 1]][b[i]];
    }
    if (a[0][b[n]] == 0) return -1;
    res += a[0][b[n]];
    return res;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (a[u][v] == 0) a[u][v] = a[v][u] = w;
        else if (w < a[u][v]) a[u][v] = a[v][u] = w;
    }
    cin >> k;
    for (int id = 1; id <= k; id++) {
        cin >> num;
        for (int i = 1; i <= num; i++) scanf("%d", &b[i]);
        if (num != n) continue;
        int res = check();
        //printf("%d %d\n", id, res);
        if (res == -1) continue;
        cnt++;
        if (res < mincost) {
            mincost = res;
            ans = id;
        }
    }
    printf("%d\n%d %d\n", cnt, ans, mincost);
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
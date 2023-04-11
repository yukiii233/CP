#include <bits/stdc++.h>
using namespace std;

const int N = 16;
int n, m, v[N], e[N], lay[N], dp[(1 << N) + 5], cost[(1 << N) + 5];

void solve() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &e[i]);
    for (int i = 1; i <= n; i++) {
        int num;
        scanf("%d", &num);
        lay[i] = 0;
        for (int j = 1; j <= num; j++) {
            int x;
            scanf("%d", &x);
            lay[i] |= 1 << x;
        }
    }
    for (int i = 0; i < (1 << (n + 1)); i++) {
        cost[i] = 0;
        for (int j = 1; j <= n; j++) if (i & (1 << j)) cost[i] += e[j];
    }
    memset(dp, -1, sizeof dp);
    dp[0] = 0;
    int res = 0;
    int i = 0, j = n;
    for (int i = 0; i < (1 << (n + 1)); i++) if (dp[i] != -1) {
        for (int j = 1; j <= n; j++) if ((((i >> j) & 1) == 0) && ((i & lay[j]) == lay[j]) && cost[i | (1 << j)] <= m) {
            dp[i | (1 << j)] = max(dp[i | (1 << j)], dp[i] + v[j]);
        }
        res = max(res, dp[i]);
    }
    printf("%d\n", res);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 17;
int n, m, dis[N][N], dp[N][(1 << N) + 5];

void solve() {
    memset(dis, 0x3f, sizeof dis);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        dis[u][v] = min(dis[u][v], w);
        dis[v][u] = min(dis[v][u], w);
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
    }
    memset(dp, 0x3f, sizeof dp);
    dp[1][2] = 0;
    for (int i = 0; i < (1 << (n + 1)); i++) {
        for (int j = 1; j <= n; j++) if (dp[j][i] != 0x3f3f3f3f) {
            //printf("%d %d\n", i, j);
            for (int k = 1; k <= n; k++) if (dis[j][k] != 0x3f3f3f3f) {
                dp[k][i | (1 << k)] = min(dp[k][i | (1 << k)], dp[j][i] + dis[j][k]);
            }
        }
    }
    int res = dp[1][(1 << (n + 1)) - 2];
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
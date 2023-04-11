#include <bits/stdc++.h>
using namespace std;

const int N = 17;
int n, m, K, L, B[N], A[N];
int dis[N][N], f[N][(1 << N) + 5], g[52][(1 << N) + 5];

int G(int s, int c) {
    if (s == 1 || c <= 0) return 0;
    int &res = g[c][s];
    if (res != -1) return res;
    res = 0;
    for (int i = 1; i <= n; i++) if ((s >> i) & 1) {
        for (int k = 1; k <= min(c, B[i] != 0 ? ((A[i] - 1) / B[i] + 1) : c); k++) {
            res = max(res, G(s ^ (1 << i), c - k) + (A[i] + A[i] - (k - 1) * B[i]) * k / 2);
        }
    }
    return res;
}

void solve() {
    memset(f, 0x3f, sizeof f);
    memset(dis, 0x3f, sizeof dis);
    memset(g, -1, sizeof g);
    scanf("%d %d %d %d", &n, &m, &K, &L);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &B[i]);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        dis[u][v] = min(dis[u][v], w);
        dis[v][u] = min(dis[v][u], w);
    }
    for (int k = 0; k <= n; k++) {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
    }
    f[0][1] = 0;
    for (int s = 0; s < (1 << (n + 1)); s++) {
        for (int i = 0; i <= n; i++) if (f[i][s] != 0x3f3f3f3f) {
            for (int j = 0; j <= n; j++) if (dis[i][j] != 0x3f3f3f3f) {
                f[j][s | (1 << j)] = min(f[j][s | (1 << j)], f[i][s] + dis[i][j]);
            } 
        }
    }
    int res = 0;
    for (int s = 0; s < (1 << (n + 1)); s++) if (f[0][s] <= L) {
        res = max(res, G(s, K));
    }
    static int Case = 0;
    printf("Case %d: %d\n", ++Case, res);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
const int N = 10 + 1, M = 1036;

int n, m, ecnt[M][M], con[M], bcon[M], mer[M][M], G[N][N], pow2[M], scon[M];
bool in(int s, int x) {
    return ((s >> x) & 1);
}

void CALC(int s) {
    int root = s & -s;
    con[s] = pow2[ecnt[s][s]];
    for (int s1 = ((s - 1) & s); s1; s1 = ((s1 - 1) & s)) if (root & s1) {
        con[s] = (1ll * con[s] + mod - con[s1] * 1ll * pow2[ecnt[s ^ s1][s ^ s1]] % mod) % mod;
    }
    mer[0][s] = 1;
    for (int s1 = ((s - 1) & s); s1; s1 = ((s1 - 1) & s)) if (root & s1) {
        int ss = (s ^ s1), rt = ss & -ss;
        for (int s2 = ss; s2; s2 = ((s2 - 1) & ss)) if (rt & s2) {
            mer[ss][s1] = (mer[ss][s1] + con[s2] * 1ll * mer[ss - s2][s1] % mod * ecnt[s2][s1] % mod) % mod;
        }
    }
    // for (int s1 = ((s - 1) & s); s1; s1 = ((s1 - 1) & s)) if (!(root & s1)) {
        // int rt = s1 & -s1;
        // for (int s2 = s1; s2; s2 = ((s2 - 1) & s1)) if (s2 & rt) {
            // mer[s1][s - s1] = (mer[s1][s - s1] + con[s2] * 1ll * ecnt[s2][s - s1] % mod * mer[s1 - s2][s - s1] % mod) % mod;
        // }
    // }
    for (int s1 = ((s - 1) & s); s1; s1 = ((s1 - 1) & s)) if (root & s1) {
        scon[s] = (scon[s] + bcon[s1] * 1ll * mer[s - s1][s1] % mod) % mod;
    }
    bcon[s] = (con[s] + mod - scon[s]) % mod;
}

void solve() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        --u, --v;
        G[u][v] = G[v][u] = 1;
    }
    for (int i = 0; i < n; i++) G[i][i] = 1;
    int mask = (1 << n) - 1;
    for (int i = 0; i <= mask; i++) {
        for (int j = 0; j <= mask; j++) if (i == j || (i & j) == 0) {
            for (int u = 0; u < n; u++) if (in(i, u)) {
                for (int v = (i == j ? u + 1 : 0); v < n; v++) if (in(j, v)) {
                    ecnt[i][j] += !G[u][v];
                }
            }
        }
    }
    for (int i = 1; i <= mask; i++) CALC(i);
    printf("%d\n", bcon[mask]);
}

int main() {
    pow2[0] = 1;
    for (int i = 1; i < M; i++) pow2[i] = (pow2[i - 1] + pow2[i - 1]) % mod;
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(ecnt, 0, sizeof ecnt);
        memset(con, 0, sizeof con);
        memset(mer, 0, sizeof mer);
        memset(G, 0, sizeof G);
        memset(bcon, 0, sizeof bcon);
        memset(scon, 0, sizeof scon);
        solve();
    }
    return 0;
}
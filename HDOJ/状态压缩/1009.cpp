#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int N = 16, M = (1 << N) + 5;
int n, m, trans[4][M], f[N], g[N], dp[2][M], ans[N];
char b[N] = "AGCT";
char S[N + 5];

void add(int &x, int y) {
    ((x += y) >= mod) && (x -= mod);
}
void solve() {
    memset(ans, 0, sizeof ans);
    scanf("%s %d", S, &m);
    n = strlen(S);
    int mask = (1 << n) - 1;
    for (int s = 0; s <= mask; s++) {
        for (int i = 0; i < n; i++) f[i] = (i ? f[i - 1] : 0) + ((s >> i) & 1);
        for (int c = 0; c < 4; c++) {
            g[0] = max(f[0], 1 * (b[c] == S[0]));
            int cur = g[0];
            for (int i = 1; i < n; i++) {
                g[i] = max(g[i - 1], f[i]);
                if (b[c] == S[i]) g[i] = max(g[i], f[i - 1] + 1);
                cur |= (g[i] - g[i - 1]) << i;
            }
            trans[c][s] = cur;
        }
    }
    int cur = 0;
    memset(dp[cur], 0, sizeof dp[cur]);
    dp[cur][0] = 1;
    for (int i = 1; i <= m; i++) {
        cur ^= 1;
        memset(dp[cur], 0, sizeof dp[cur]);
        for (int c = 0; c < 4; c++) {
            for (int s = 0; s <= mask; s++) add(dp[cur][trans[c][s]], dp[cur ^ 1][s]);
        }
    }
    for (int s = 0; s <= mask; s++) add(ans[__builtin_popcount(s)], dp[cur][s]);
    for (int i = 0; i <= n; i++) printf("%d\n", ans[i]);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
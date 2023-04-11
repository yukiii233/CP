#include <bits/stdc++.h>
using namespace std;

const int N = 17;
int n, a[N], p[N], dp[N][(1 << N) + 5];

void solve() {
    memset(dp, -0x3f, sizeof dp);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d %d", &a[i], &p[i]);
    for (int i = 0; i < n; i++) if (p[i] == -1 || p[i] == 0) dp[i][1 << i] = 0;
    for (int i = 0; i < (1 << n); i++) {
        int cnt = __builtin_popcount(i);
        for (int j = 0; j < n; j++) if (dp[j][i] != -0x3f3f3f3f) {
            for (int k = 0; k < n; k++) if (!((i >> k) & 1) && (p[k] == -1 || p[k] == cnt)) {
                dp[k][i | (1 << k)] = max(dp[k][i | (1 << k)], dp[j][i] + a[j] * a[k]);
            }
        }
    }
    int res = -0x3f3f3f3f;
    for (int i = 0; i < n; i++) res = max(res, dp[i][(1 << n) - 1]);
    static int Case = 1;
    printf("Case #%d:\n%d\n", Case++, res);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
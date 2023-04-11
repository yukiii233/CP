#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 2000 + 5;

int n;
int p[N][N], a[N], dp[N][N], s[N];

void solve() {
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i + n] = a[i];
    int m = n + n;
    for (int i = 1; i <= m; i++) s[i] = s[i - 1] + a[i], p[i][i] = i;
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= m; i++) dp[i][i] = 0;
    for (int len = 2; len <= m; len++) {
        for (int i = 1; i + len - 1 <= m; i++) {
            int j = i + len - 1;
            for (int k = p[i][j - 1]; k <= p[i + 1][j] && k < j; k++) {
                if (dp[i][j] > dp[i][k] + dp[k + 1][j] + s[j] - s[i - 1]) {
                    dp[i][j] = dp[i][k] + dp[k + 1][j] + s[j] - s[i - 1];
                    p[i][j] = k;
                }
            }
        }
    }
    int res = 2E9;
    for (int i = 1; i <= n; i++) res = min(res, dp[i][i + n - 1]);
    printf("%d\n", res);
}

int main() {
    while (scanf("%d", &n) == 1) {
        solve();
    }
    return 0;
}
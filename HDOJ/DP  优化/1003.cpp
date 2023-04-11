#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 2000 + 5;

int n, m, a[N], b[N], as[N], bs[N], w;
int dp[N][N];
int q[N], ql, qr;

void solve() {
    scanf("%d %d %d", &n, &m, &w);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d %d", &a[i], &b[i], &as[i], &bs[i]);
    }
    memset(dp, -0x3f, sizeof dp);
    for (int i = 1; i <= w + 1; i++) {
        for (int j = 0; j <= as[i]; j++) dp[i][j] = -a[i] * j;
    }
    for (int i = 1; i <= w + 1; i++) {
        for (int j = 0; j <= m; j++) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
    }
    for (int i = w + 2; i <= n; i++) {
        int p = i - w - 1;
        for (int j = 0; j <= m; j++) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        ql = 0, qr = -1;
        for (int j = m; j >= 0; j--) {
            while (ql <= qr && q[ql] - j > bs[i]) ql++;
            while (ql <= qr && dp[p][q[qr]] + q[qr] * b[i] <= dp[p][j] + j * b[i]) qr--;
            q[++qr] = j;
            dp[i][j] = max(dp[i][j], dp[p][q[ql]] + q[ql] * b[i] - j * b[i]);
        }
        ql = 0, qr = -1;
        for (int j = 0; j <= m; j++) {
            while (ql <= qr && j - q[ql] > as[i]) ql++;
            while (ql <= qr && dp[p][q[qr]] + q[qr] * a[i] <= dp[p][j] + j * a[i]) {
                qr--;
            }
            q[++qr] = j;
            dp[i][j] = max(dp[i][j], dp[p][q[ql]] + q[ql] * a[i] - j * a[i]);
        }
    }
    printf("%d\n", dp[n][0]);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
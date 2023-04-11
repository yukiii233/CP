#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1000 + 5;

int n, x[N], y[N], dp[N][N], s[N][N];
int w(int i, int j, int k) { return y[k] - y[j] + x[k + 1] - x[i]; }

void solve() {
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= n; i++) dp[i][i] = 0, s[i][i] = i;
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i]; 
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            for (int k = s[i][j - 1]; k <= s[i + 1][j] && k < j; k++) {
                if (dp[i][j] > dp[i][k] + dp[k + 1][j] + w(i, j, k)) {
                    dp[i][j] = dp[i][k] + dp[k + 1][j] + w(i, j, k);
                    s[i][j] = k;
                }
            }
        }
    }
    cout << dp[1][n] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    while (cin >> n) {
        solve();
    }
    return 0;
}
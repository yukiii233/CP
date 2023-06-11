#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 100 + 1;

int n, a, b, p, q;
int dp[N * 2][N][N];

int fpow(int a, int b) {
    int res = 1;
    for (; b; b >>= 1, a = a * 1ll * a % mod) if (b & 1) res = res * 1ll * a % mod;
    return res;
}
int inv(int x) {
    return fpow(x, mod - 2);
}

void solve() {
    cin >> n >> a >> b >> p >> q;
    int cur = 1;
    dp[0][a][b] = 1;
    int ip = inv(p), iq = inv(q);
    for (int k = 1; k <= n * 2; k++) {
        cur ^= 1;
        if (cur == 0) {
            for (int r = 1; r <= p; r++) {
                for (int i = a; i < n; i++) {
                    for (int j = b; j < n; j++) {
                        int to = min(i + r, n);
                        dp[k][to][j] = (dp[k][to][j] + dp[k - 1][i][j] * 1ll * ip % mod) % mod;
                    }
                }
            }
        } else {
            for (int r = 1; r <= q; r++) {
                for (int i = a; i < n; i++) {
                    for (int j = b; j < n; j++) {
                        int to = min(j + r, n);
                        dp[k][i][to] = (dp[k][i][to] + dp[k - 1][i][j] * 1ll * iq % mod) % mod;
                    }
                }
            } 
        }
    }
    int res = 0;
    for (int k = 1; k <= n * 2; k++) {
        for (int i = b; i < n; i++) {
            res = (res + dp[k][n][i]) % mod;
        }
    }
    cout << res << '\n';
}

signed main() {
    //freopen("E.txt", "w", stdout);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N =  10005;

int n, m;
ll a[N], dp[2][N];
int q[N], ql, qr, cur;

ll x(int i) { return 2 * a[i + 1]; }
ll y(int i) { return dp[cur ^ 1][i] + a[i + 1] * a[i + 1]; } 

void solve() {
    cin >> n >> m;
    if (m > n) m = n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    memset(dp, 0x3f, sizeof dp);
    dp[cur][0] = 0;
    sort(a + 1, a + n + 1);
    for (int r = 1; r <= m; r++) {
        cur ^= 1;
        memset(dp[cur], 0x3f, sizeof dp[cur]);
        q[ql = qr = 0] = 0;
        for (int i = 1; i <= n; i++) {
            while (ql < qr && (y(q[ql + 1]) - y(q[ql]) <= (x(q[ql + 1]) - x(q[ql])) * a[i])) ql++;
            dp[cur][i] = y(q[ql]) - a[i] * x(q[ql]) + a[i] * a[i];
            //cout << i << ' ' << q[ql] << '\n';
            if (dp[cur ^ 1][i] >= 0x3f3f3f3f) continue;
            while (ql < qr && (y(i) - y(q[qr])) * (x(q[qr]) - x(q[qr - 1])) <= 
                (x(i) - x(q[qr])) * (y(q[qr]) - y(q[qr - 1]))) qr--;
            q[++qr] = i;
        }
    }
    static int Case = 0;
    cout << "Case " << ++Case << ": ";
    cout << dp[cur][n] << '\n';
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
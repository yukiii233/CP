#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1000 + 5;
const ll INF = 1e15;

int n, m, cur;
ll a[N], dp[2][N], s[N], s2[N];
int q[N], ql, qr;

ll y(int i) { return 2 * dp[cur ^ 1][i] + s2[i] + s[i] * s[i]; }
ll x(int i) { return 2 * s[i]; }

void solve() {
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
        s2[i] = s2[i - 1] + a[i] * a[i];
    }
    for (int i = 0; i <= 1; i++) fill(dp[i], dp[i] + n + 1, INF);
    dp[cur][0] = 0;
    for (int r = 1; r <= m; r++) {
        cur ^= 1;
        fill(dp[cur], dp[cur] + n + 1, INF);
        q[ql = qr = 0] = 0;
        for (int i = 1; i <= n; i++) {
            while (ql < qr && (y(q[ql + 1]) - y(q[ql]) <= (x(q[ql + 1]) - x(q[ql])) * s[i])) ql++;
            dp[cur][i] = (y(q[ql]) - s[i] * x(q[ql]) + s[i] * s[i] - s2[i]) / 2;
            if (dp[cur ^ 1][i] == INF) continue;
            while (ql < qr && (y(i) - y(q[qr])) * (x(q[qr]) - x(q[qr - 1])) <= 
                (x(i) - x(q[qr])) * (y(q[qr]) - y(q[qr - 1]))) qr--;
            q[++qr] = i;
        }
    }
    printf("%lld\n", dp[cur][n]);
}

int main() {
    while (scanf("%d %d", &n, &m) && (n != 0 || m != 0)) {
        m += 1;
        solve();
    }
    return 0;
}
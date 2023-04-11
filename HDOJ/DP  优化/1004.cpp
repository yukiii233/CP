#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e6 + 5;

int n, k, t;
int dp[N], q[N], ql, qr;

void solve() {
    scanf("%d %d %d", &n, &k, &t);
    memset(dp, 0x3f, sizeof dp);
    dp[n] = 0;
    q[ql = qr = 0] = n;
    for (int i = n - 1; i; i--) {
        while (ql <= qr && q[ql] - i > t) ql++;
        if (ql <= qr) dp[i] = dp[q[ql]] + 1;
        if (i * 1ll * k <= n) dp[i] = min(dp[i], dp[i * k] + 1);
        while (ql <= qr && dp[q[qr]] >= dp[i]) qr--;
        q[++qr] = i;
    }
    printf("%d\n", dp[1]);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 5e5 + 5;

int n, m;
ll s[N], dp[N];
int q[N], ql, qr;

ll x(int i) { return s[i] + s[i]; }
ll y(int i) { return dp[i] + s[i] * s[i]; }


void solve() {
    for (int i = 1; i <= n; i++) scanf("%lld", &s[i]), s[i] += s[i - 1];
    q[ql = qr = 0] = 0;
    for (int i = 1; i <= n; i++) {
        while (ql < qr && y(q[ql + 1]) - y(q[ql]) <= s[i] * (x(q[ql + 1]) - x(q[ql]))) ql++;
        dp[i] = y(q[ql]) - s[i] * x(q[ql]) + s[i] * s[i] + m;
        while (ql < qr && (y(i) - y(q[qr])) * (x(q[qr]) - x(q[qr - 1])) <= 
            (x(i) - x(q[qr])) * (y(q[qr]) - y(q[qr - 1]))) qr--;
        q[++qr] = i;
    }
    printf("%lld\n", dp[n]);
}

int main() {
    while (scanf("%d %d", &n, &m) == 2) {
        solve();
    }
    return 0;
}
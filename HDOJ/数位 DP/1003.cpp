#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 20;
ll a, b;
int cnt, dig[N];
ll f[2][N][1543], g[2][N][1543];

ll dfsf(int p, int sum, int C, int D, int limit) {
    if (p == D) return sum == 0;
    ll &re = f[limit][p][sum];
    if (re != -1) return re;
    re = 0;
    int mx = limit ? dig[p] : 9;
    for (int i = 0; i <= mx; i++) {
        re += dfsf(p - 1, sum - i * abs(p - C), C, D, limit && i == mx);
    }
    return re;
}
ll dfsg(int p, int sum, int C, int D, int limit) {
    if (p == D) return sum == 0;
    ll &re = g[limit][p][sum];
    if (re != -1) return re;
    re = 0;
    int mx = limit ? dig[p] : 9;
    for (int i = 0; i <= mx; i++) {
        re += dfsg(p - 1, sum - i * abs(p - C), C, D, limit && i == mx);
    }
    return re;
}

ll solve(ll x) {
    if (x < 0) return 0;
    cnt = 0;
    while (x) {
        dig[++cnt] = x % 10;
        x /= 10;
    }
    ll res = 0;
    for (int i = 1; i <= cnt; i++) {
        memset(f, -1, sizeof f);
        memset(g, -1, sizeof g);
        ll re = 0;
        for (int j = i + 1; j <= cnt; j++) re += (j - i) * dig[j];
        res += dfsf(i - 1, re, i, 0, 1);
        res += dig[i] * dfsf(i - 1, re, i, 0, 0);
        for (int sum = 0; sum <= 9 * min(i - 1, cnt - i) * (min(i - 1, cnt - i) + 1) / 2; sum++) {
            if (sum != re) {
                res += 10 * dfsf(i - 1, sum, i, 0, 0) * dfsg(cnt, sum, i, i, 1);
            } else {
                res += 10 * dfsf(i - 1, sum, i, 0, 0) * (dfsg(cnt, sum, i, i, 1) - 1);
            }
        }
    }
    return res - cnt;
}
void solve() {
    scanf("%lld %lld", &a, &b);
    printf("%lld\n", solve(b) - solve(a - 1) + (a == 0));
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
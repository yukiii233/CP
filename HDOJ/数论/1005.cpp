#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;

int n;
ll r[N], m[N];

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b) {
        ll d = exgcd(b, a % b, y, x);
        return y -= a / b * x, d;
    } else return x = 1, y = 0, a;
}
ll qpow(ll a, ll b, ll mod) {
    ll res = 0, f = 1;
    if (b < 0) f = -1, b = -b;
    for (; b; b >>= 1, a = (a + a) % mod) if (b & 1) res = (res + a) % mod;
    return res * f;
}
ll exCRT() {
    for (int i = 2; i <= n; i++) {
        ll x, y;
        ll g = exgcd(m[i], m[i - 1], x, y);
        if ((r[i] - r[i - 1]) % g != 0) return -1;
        ll t = m[i - 1] / g;
        x = qpow(x, (r[i] - r[i - 1]) / g, t);
        x = (x + t) % t;
        r[i] -= qpow(x, m[i], m[i] / g * m[i - 1]);
        m[i] = m[i] / g * m[i - 1];
        r[i] = (r[i] + m[i]) % m[i];
    }
    if (r[n] == 0) r[n] += m[n];
    return r[n];
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &m[i]);
    for (int i = 1; i <= n; i++) scanf("%lld", &r[i]);
    static int Case = 0;
    printf("Case %d: %lld\n", ++Case, exCRT());
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
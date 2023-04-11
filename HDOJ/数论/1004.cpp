#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define end start
const int end = 21252;
const int N = 1e5 + 5;

int Case;
int n;
ll a, b, c, d;

ll r[5], m[5];

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
    return r[n];
}

void solve() {
    ll re;
    if (a == 0 || b == 0 || c == 0) re = end - d;
    else {
        n = 3;
        r[1] = a, r[2] = b, r[3] = c;
        m[1] = 23, m[2] = 28, m[3] = 33;
        re = exCRT() - d;
    }
    while (re < 0) re += m[3];
    printf("Case %d: the next triple peak occurs in %lld days.\n", ++Case, re);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        Case = 0;
        while (~scanf("%lld %lld %lld %lld", &a, &b, &c, &d) && d != -1) solve();
    }
    return 0;
}
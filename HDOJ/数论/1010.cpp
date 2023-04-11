#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, y, x, s;
int mod;
bool M;

ll read() {
    ll res = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9') {
        res = res * 10 + ch - '0';
        ch = getchar();
    }
    return res;
}

int mul(int a, int b) {
    if ((a * 1ll * b) >= mod) M = 1;
    return (a * 1ll * b) % mod;
}
int add(int a, int b) {
    if ((a + b) >= mod) M = 1;
    return (a + b) % mod;
}
struct Martix {
    int x, y, f[5][5];
    Martix(int X, int Y) {
        x = X, y = Y;
        memset(f, 0, sizeof f);
    }
    Martix operator * (const Martix &q) const {
        Martix t(x, q.y);
        for (int i = 1; i <= t.x; i++)
            for (int j = 1; j <= t.y; j++)
                for (int k = 1; k <= y; k++) t.f[i][j] = add(t.f[i][j], mul(f[i][k], q.f[k][j]));
        return t;
    }
};

Martix fpow(Martix a, long long b) {
    Martix e(4, 4);
    for (int i = 1; i <= 4; i++) e.f[i][i] = 1;
    for (; b; b >>= 1, a = a * a) if (b & 1) e = e * a;
    return e;
}
int qpow(int a, int b, int mod) {
    int res = 1;
    for (; b; b >>= 1, a = a * 1ll * a % mod) if (b & 1) res = res * 1ll * a % mod;
    return res;
}
int getphi(int x) {
    int res = 1;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            x /= i;
            res *= (i - 1);
            while (x % i == 0) {
                x /= i;
                res *= i;
            }
        }
    }
    if (x > 1) res *= (x - 1);
    return res;
}

void solve() {
    n = read(), y = read(), x = read(), s = read();
    mod = getphi(s + 1);
    Martix b(4, 4), a(1, 4);
    b.f[1][1] = 1, b.f[2][1] = 4, b.f[3][1] = 1, b.f[4][1] = 4;
    b.f[2][2] = 4, b.f[3][2] = 1, b.f[4][2] = 4, b.f[2][3] = 1;
    b.f[2][4] = 2, b.f[4][4] = 1; 
    a.f[1][1] = 1, a.f[1][2] = 1;
    if (n * y == 0) return printf("%d\n", 1), void();
    if (n * y == 1) return printf("%lld\n", x % (s + 1)), void();
    a = a * fpow(b, n * y - 1ll);
    ll re = a.f[1][1];
    printf("%lld\n", qpow(x, re + (M ? mod : 0), s + 1));
}

int main() {     
    int T = read();
    while (T--) {
        solve();
    }
    return 0;
}
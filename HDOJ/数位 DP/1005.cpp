#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;
const int N = 20;

int pow10[N], p10[N];
int cnt, dig[N];

struct node {
    int cnt, sum, sum2;
    node(): cnt(-1), sum(0), sum2(0) {}
} f[N][8][8];

void add(int &x, int y) {
    ((x += y) >= mod) && (x -= mod);
}
node dfs(int p, int dm, int vm, int limit) {
    if (p == 0) {
        node tmp;
        tmp.cnt = dm && vm;
        return tmp;
    }
    node &re = f[p][dm][vm];
    if (!limit && re.cnt != -1) return re;
    node res;
    res.cnt = 0;
    int mx = limit ? dig[p] : 9;
    for (int i = 0; i <= mx; i++) if (i != 7) {
        node nxt = dfs(p - 1, (dm + i) % 7, (vm + p10[p - 1] * 1ll * i % 7) % 7, limit && i == mx);
        add(res.cnt, nxt.cnt);
        add(res.sum, nxt.cnt * 1ll * pow10[p - 1] % mod * i % mod);
        add(res.sum, nxt.sum);
        add(res.sum2, (pow10[p - 1] * 1ll * i % mod * pow10[p - 1] % mod * i % mod * nxt.cnt % mod + nxt.sum2) % mod);
        add(res.sum2, pow10[p - 1] * 2ll * i % mod * nxt.sum % mod);
    }
    if (!limit) re = res;
    return res;
}

int calc(ll x) {
    cnt = 0;
    while (x) {
        dig[++cnt] = x % 10;
        x /= 10;
    }
    for (int i = 0; i <= cnt; i++)
        for (int j = 0; j < 8; j++)
            for (int k = 0; k < 8; k++) f[i][j][k].cnt = -1, f[i][j][k].sum = f[i][j][k].sum2 = 0;
    return dfs(cnt, 0, 0, 1).sum2;
}

void solve() {
    ll a, b;
    scanf("%lld %lld", &a, &b);
    printf("%d\n", (calc(b) - calc(a - 1) + mod) % mod);
}

int main() {
    pow10[0] = 1;
    for (int i = 1; i < N; i++) pow10[i] = pow10[i - 1] * 10ll % mod;
    p10[0] = 1;
    for (int i = 1; i < N; i++) p10[i] = p10[i - 1] * 10ll % 7;
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
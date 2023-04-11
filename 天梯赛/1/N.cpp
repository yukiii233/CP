#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7, i2 = (mod + 1) / 2;
const int N = 3e5 + 5;

int n, r;
vector<int> G[N];

int fpow(int a, int b) {
    int res = 1;
    for (; b; b >>= 1, a = a * 1ll * a % mod) if (b & 1) res = res * 1ll * a % mod;
    return res;
}
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b) {
        ll d = exgcd(b, a % b, y, x);
        return y -= a / b * x, d;
    } else return x = 1, y = 0, a;
}
int getinv(int v) {
    return fpow(v, mod - 2);
    // ll x, y;
    // exgcd(v, mod, x, y);
    // return (x % mod + mod) % mod;
}
int fac[N], ifac[N];
void init_binom(int n) {
    fac[0] = ifac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * 1ll * i % mod;
    ifac[n] = getinv(fac[n]);
    for (int i = n; i > 1; i--) ifac[i - 1] = ifac[i] * 1ll * i % mod;
}
int binom(int a, int b) {
    if (b < 0 || a < 0 || b > a) return 0;
    return fac[a] * 1ll * ifac[b] % mod * ifac[a - b] % mod; 
}

int f[N], son[N], tr[N], ans;
int lowbit(int x) {
    return x & -x;
}
void add(int x, int v) {
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += v;
}
int qry(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

void dfs(int u, int fa) {
    int res = 1;
    for (int v : G[u]) if (v != fa) {
        son[u]++;
        dfs(v, u);
        res = res * 1ll * f[v] % mod;
    }
    f[u] = res * 1ll * fac[son[u]] % mod;
}
void dfs(int u, int fa, int dep) {
    add(u, 1);
    for (int v : G[u]) if (v != fa) {
        dfs(v, u, dep + 1);
    }
    add(u, -1);
    int res = qry(u);
    ans += (dep - res * 2ll + mod) % mod * 1ll * f[r] % mod * i2 % mod;
    ans %= mod;
}

void solve() {
    scanf("%d %d", &n, &r);
    init_binom(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(r, r);
    ans = f[r] * 1ll * i2 % mod * n % mod * (n - 1) % mod * i2 % mod;
    dfs(r, r, 0);
    printf("%d\n", ans);
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
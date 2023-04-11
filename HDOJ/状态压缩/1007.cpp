#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 17;
const int inv2 = (mod + 1) / 2;

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
void add(int &x, int y) {
    ((x += y) >= mod) && (x -= mod);
}
bool in(int s, int x) {
    return ((s >> x) & 1);
}
int n, m, G[N][N], deg[N], a[N][N];
int dp[N][(1 << 17) + 1];

int Gauss(int n) {
    int res = 1;
    for (int i = 1; i <= n; i++) {
        if (!a[i][i]) {
            for (int j = i + 1; j <= n; j++) if (a[j][i] != 0) {
                for (int k = 1; k <= n; k++) swap(a[i][k], a[j][k]);
                break;
            }
        }
        if (a[i][i] == 0) return 0;
        for (int j = i + 1; j <= n; j++) {
            if (!a[j][i]) continue;
            int t = a[j][i] * 1ll * getinv(a[i][i]) % mod;
            for (int k = i; k <= n; k++) add(a[j][k], mod - a[i][k] * 1ll * t % mod); 
        }
        res = res * 1ll * a[i][i] % mod;
    }
    return res;
}

void solve() {
    memset(G, 0, sizeof G);
    memset(deg, 0, sizeof deg);
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;
        G[u][v] = G[v][u] = 1;
        deg[u]++;
        deg[v]++;
    }
    int mask = (1 << n) - 1;
    for (int i = 0; i < n; i++) {
        dp[i][1 << i] = 1;
        for (int s = 1; s <= mask; s++) if ((s != (1 << i)) && in(s, i) && (s & -s) == (1 << i)) {
            for (int j = i + 1; j < n; j++) if (in(s, j)) {
                int s1 = (s ^ (1 << j));
                for (int k = i; k < n; k++) if (in(s1, k) && G[k][j]) add(dp[j][s], dp[k][s1]);
            }
        }
    }
    int res = 0;
    for (int s = 3; s <= mask; s++) {
        memset(a, 0, sizeof a);
        int cnt = __builtin_popcount(s);
        if (cnt < 3) continue;
        int p = __builtin_ffs(s) - 1, re = 0;
        for (int i = 0; i < n; i++) if (i != p && in(s, i) && G[i][p]) add(re, dp[i][s]);
        re = re * 1ll * inv2 % mod;
        int pos = n - cnt + 1;
        for (int i = 0; i < n; i++) if (!in(s, i)) {
            for (int j = 0; j < n; j++) if (in(s, j)) {
                add(a[pos][pos], G[i][j]);
            } 
        }
        int r = 0, c;
        for (int i = 0; i < n; i++) if (!in(s, i)) {
            ++r;
            c = 0;
            for (int j = 0; j < n; j++) if (!in(s, j)) {
                a[r][++c] = (i == j) ? deg[i] : mod - G[i][j];
            } else {
                add(a[pos][r], mod - G[i][j]);
                add(a[r][pos], mod - G[i][j]);
            }
        }
        add(res, re * 1ll * Gauss(pos - 1) % mod);
    }
    printf("%d\n", res);
}

int main() {
    while (~scanf("%d %d", &n, &m)) {
        solve();
    }
    return 0;
}
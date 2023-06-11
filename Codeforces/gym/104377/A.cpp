#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;
const int N = 500 + 5;

ll n;
int m;
map<int, int> f[51], g[51];
map<int, bool> vis[51];

int fac[N], ifac[N];
int fpow(int a, int b) {
	int res = 1;
	for (; b; b >>= 1, a = a * 1ll * a % mod) if (b & 1) res = res * 1ll * a % mod;
	return res;
}
void init_binom(int n) {
	fac[0] = ifac[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * 1ll * i % mod;
	ifac[n] = fpow(fac[n], mod - 2);
	for (int i = n; i > 1; i--) ifac[i - 1] = ifac[i] * 1ll * i % mod;
}
int binom(int a, int b) {
	return fac[a] * 1ll * ifac[b] % mod * ifac[a - b] % mod;
}
void add(int& a, int b) {
	((a += b) >= mod) && (a -= mod);
}

void dfs(int p, ll res) {
	if (res < 0 || res >= m * 1ll * (1ll << (p + 1))) return;
	if (vis[p].count(res)) return;
	vis[p][res] = 1;
	if (p == 0) {
		add(g[p][res], binom(m, res));	
		if (res & 1) add(f[p][res], binom(m, res));
		return;
	}
	for (int i = 0; i <= m && i * 1ll * (1ll << p) <= res; i++) {
		dfs(p - 1, res - i * 1ll * (1ll << p));
		add(f[p][res], binom(m, i) * 1ll * ((f[p - 1][res - i * 1ll * (1ll << p)] + ((i & 1) ? (i * 1ll * (1ll << p) % mod * g[p - 1][res - i * 1ll * (1ll << p)] % mod) : 0)) % mod) % mod);
		add(g[p][res], binom(m, i) * 1ll * g[p - 1][res - i * 1ll * (1ll << p)] % mod);
	}
}


void solve() {
	scanf("%lld %d", &n, &m);
	dfs(50, n);
	printf("%d\n", f[50][n]);
}

int main() {
	init_binom(N - 1);
	int T = 1;
	while (T--) {
		solve();
	}
	return 0;
}
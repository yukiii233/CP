#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7, i2 = (mod + 1) / 2;
const int N = 2e5 + 5;

int n, k, down[N], down2[N], siz[N];
vector<int> G[N];

int fpow(int a, int b) {
	int res = 1;
	for (; b; b >>= 1, a = a * 1ll * a % mod) if (b & 1) {
		res = res * 1ll * a % mod;
	}
	return res;
}
void add(int &x, int y) {
	((x += y) >= mod) && (x -= mod);
}
void getdown(int u, int fa) {
	for (int v : G[u]) {
		if (v == fa) continue;
		getdown(v, u);
		add(down2[u], siz[v] * 1ll * down[u] % mod);
		add(down[u], siz[u] * 1ll * siz[v] % mod);
		siz[u] += siz[v];
	}
	siz[u]++;
}
int fac[N], ifac[N];
void init_binom(int n) {
    fac[0] = ifac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * 1ll * i % mod;
    ifac[n] = fpow(fac[n], mod - 2);
    for (int i = n; i > 1; i--) ifac[i - 1] = ifac[i] * 1ll * i % mod;
}
int binom(int a, int b) {
    if (b < 0 || a < 0 || b > a) return 0;
    return fac[a] * 1ll * ifac[b] % mod * ifac[a - b] % mod; 
}

void solve() {
	scanf("%d %d", &n, &k);
	init_binom(n);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	getdown(1, 1);
	if (k == 1) puts("1");
	else if (k == 2) {
		int res = 0;
		for (int i = 1; i <= n; i++) {
			add(res, down[i]);
			add(res, (siz[i] - 1) * 1ll * (n - siz[i]) % mod);
			add(res, n - 1);
		}
		res = res * 1ll * fpow(n * 1ll * (n - 1) % mod * i2 % mod, mod - 2) % mod;
		printf("%d\n", res);
	} else if (k == 3) {
		int res = 0;
		for (int i = 1; i <= n; i++) {
			add(res, down[i] * 1ll * (n - siz[i]) % mod);
			add(res, down2[i]);
			add(res, down[i]);
			add(res, (siz[i] - 1) * 1ll * (n - siz[i]) % mod);
		}
		res = res * 1ll * fpow(binom(n, 3), mod - 2) % mod;
		printf("%d\n", res);
	}
}

int main() {
	int T = 1;
	while (T--) {
		solve();
	}
}
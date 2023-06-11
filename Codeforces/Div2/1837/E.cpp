#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e6 + 5;

int k, n, a[N], fac[N];

bool inner(int x, int l, int r) {
	return x >= l && x <= r;
}
int calc(int k) {
	if (k == 0) return 1;
	int l = (1 << (k - 1)) + 1, r = (1 << k);
	int ord = 1, re = 0;
	for (int i = 1; i <= r; i += 2) {
		if (inner(a[i], l, r) && inner(a[i + 1], l, r)) return 0;
		if ((a[i] && !inner(a[i], l, r)) && (a[i + 1] && !inner(a[i + 1], l, r))) return 0;
		if (inner(a[i], l, r) || inner(a[i + 1], l, r)) continue;
		if (!inner(a[i], l, r) && !inner(a[i + 1], l, r)) {
			if (!a[i] && !a[i + 1]) ord = ord * 2ll % mod, re++;
			else re++;
		}
	}
	for (int i = 2; i <= r; i += 2) {
		if (a[i] < a[i - 1]) swap(a[i], a[i - 1]);
		if (!a[i] && !a[i - 1]) a[i >> 1] = 0;
		else if (!a[i - 1]) {
			if (inner(a[i], l, r)) a[i >> 1] = 0;
			else a[i >> 1] = a[i];
		} else a[i >> 1] = a[i - 1];
	}
	return calc(k - 1) * 1ll * ord % mod * fac[re] % mod;
}

void solve() {
	scanf("%d", &k);
	n = (1 << k);
	fac[0] = 1;
	for (int i = 1; i <= n; i++) {
		int x;
		fac[i] = fac[i - 1] * 1ll * i % mod;
		scanf("%d", &x);
		if (x != -1) a[i] = x;
	}
	printf("%d\n", calc(k));
}

int main() {
	int T = 1;
	while (T--) {
		solve();
	}
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
	int n;
	scanf("%d", &n);
	vector<int> a(n + 1), b(n + 1), f(n + 1, 1), g(n + 1, 1), c(n + n + 1), d(n + n + 1);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	for (int i = 1; i <= n; i++) {
		if (a[i] == a[i - 1]) f[i] = f[i - 1] + 1;
		c[a[i]] = max(c[a[i]], f[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (b[i] == b[i - 1]) g[i] = g[i - 1] + 1;
		d[b[i]] = max(d[b[i]], g[i]);
	}
	int res = 0;
	for (int i = 1; i <= n + n; i++) res = max(res, d[i] + c[i]);
	printf("%d\n", res);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
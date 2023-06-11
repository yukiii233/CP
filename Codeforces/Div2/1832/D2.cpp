#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define int long long
const int mod = 998244353;
const int N = 2e5 + 5;

int n, q, k, a[N], pre[N];
ll sum;

void solve() {
	scanf("%lld %lld", &n, &q);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	pre[0] = INT_MAX;
	for (int i = 1; i <= n; i++) sum += a[i] - (i - 1), pre[i] = min(pre[i - 1], a[i] - (i - 1));
	while (q--) {
		scanf("%lld", &k);
		if (k < n) {
			printf("%lld ", min(pre[k] + k, a[k + 1]));
		} else if (k % 2 == n % 2) {
			ll re = sum - pre[n] * 1ll * n;
			int u = k;
			k = (k - n) / 2;
			if (k <= re) printf("%lld ", pre[n] + u);
			else  k-= re, printf("%lld ", (pre[n] + u) - (k - 1) / n - 1);
		} else {
			ll re = sum + n - 1 + (n - 1) * 1ll * k - min((pre[n - 1] + k) * 1ll * n, n * 1ll * a[n]);
			int u = k;
			k = (k - n + 1) / 2;
			if (k <= re) printf("%lld ", min(pre[n] + u, a[n]));
			else k -= re, printf("%lld ", min(pre[n] + u, a[n]) - (k - 1) / n - 1);
		}
	}
}

signed main() {
	int T = 1;
	while (T--) {
		solve();
	}
}
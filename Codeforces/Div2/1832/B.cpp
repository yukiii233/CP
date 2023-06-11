#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 2e5 + 5;

int n, k, a[N];
ll sum[N];

void solve() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) 
		sum[i] = sum[i - 1] + a[i];
	ll ans = 0;
	for (int i = 0; i <= k; i++) {
		int l = 2 * i + 1, r = n - (k - i);
		ans = max(ans, sum[r] - sum[l - 1]);
	}
	printf("%lld\n", ans);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
}
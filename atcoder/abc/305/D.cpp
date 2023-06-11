#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 2e5 + 5;

int n, Q;
int a[N], dp[N];

int get(int l, int r) {
	int p1 = lower_bound(a + 1, a + n + 1, l) - a;
	int res = 0;
	if (p1 & 1) res += a[p1] - l;
	int p2 = lower_bound(a + 1, a + n + 1, r) - a;
	if (p1 == p2) return p2 % 2 ? r - l : 0;
	if (a[p2] != r) {
		if (p2 & 1) {
			p2--;
			res += r - a[p2];
		}
	}
	res += dp[p2] - dp[p1];
	return res;
}

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 3; i <= n; i++) {
		if (i & 1) {
			dp[i] = dp[i - 1] + a[i] - a[i - 1];
		} else dp[i] = dp[i - 1];
	}
	scanf("%d", &Q);
	while (Q--) {
		int l, r;
		scanf("%d %d", &l, &r);
		printf("%d\n", get(l, r));
	}
}

int main() {
	int T = 1;
	while (T--) {
		solve();
	}
	return 0;
}
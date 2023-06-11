#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 10000 + 5;

int n, m, b[N];

void solve() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n * m; i++)
		scanf("%d", &b[i]);
	sort(b + 1, b + n * m + 1);
	ll res = (b[n * m] - b[1]) * 1ll * (max(n, m) - 1) +
			(b[n * m] - b[2]) * 1ll * (min(n, m) - 1) + (b[n * m] - b[1]) * 1ll * (n * m - n - m + 1);
	res = max(res, (b[n * m] - b[1]) * 1ll * (min(n, m) - 1) +
			(b[n * m] - b[2]) * 1ll * (max(n, m) - 1) + (b[n * m] - b[1]) * 1ll * (n * m - n - m + 1));
	res = max(res, (b[n * m] - b[1]) * 1ll * (min(n, m) - 1) +
			(b[n * m - 1] - b[1]) * 1ll * (max(n, m) - 1) + (b[n * m] - b[1]) * 1ll * (n * m - n - m + 1));
	res = max(res, (b[n * m] - b[1]) * 1ll * (max(n, m) - 1) +
			(b[n * m - 1] - b[1]) * 1ll * (min(n, m) - 1) + (b[n * m] - b[1]) * 1ll * (n * m - n - m + 1));
	printf("%lld\n", res);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

int n, k;
int a[N], b[N];

void solve() {
	ll sum = 0;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (i > 1) b[i - 1] = abs(a[i] - a[i - 1]);
		sum += b[i - 1];
	}
	sort(b + 1, b + n, greater<int>());
	for (int i = 1; i < k; i++) sum -= b[i];
	printf("%lld\n", sum);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
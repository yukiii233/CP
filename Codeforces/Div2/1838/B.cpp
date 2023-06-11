#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 2e5 + 5;

int n, a[N], p[N];

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), p[a[i]] = i;
	if (abs(p[1] - p[2]) != 1) {
		int l = min(p[1], p[2]);
		printf("%d %d\n", l + 1, p[n]);
	} else {
		int l = min(p[1], p[2]), r = max(p[1], p[2]);
		if (p[n] < l) printf("%d %d\n", p[n], l);
		else if (p[n] > r) printf("%d %d\n", p[n], r);
		else printf("%d %d\n", 1, 1);
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
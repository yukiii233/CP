#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
	int n;
	scanf("%d", &n);
	vector<int> a(n + 1), b(n + 1);
	int lim = sqrt(2 * n);
	vector<vector<int>> fr(lim + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	for (int i = 1; i <= n; i++) if (a[i] <= lim) fr[a[i]][b[i]]++;
	ll res = 0;
	for (int i = 1; i <= lim; i++) {
		for (int j = 1; j <= n; j++) {
			if (i * i - j >= j  && i * i - j <= n) {
				if (j + j == i * i) res += (fr[i][j] * 1ll * fr[i][j] - fr[i][j]) / 2;
				else res += fr[i][j] * 1ll * fr[i][i * i - j];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= min(2 * n / a[i], a[i] - 1); j++) {
			if (a[i] * 1ll * j - b[i] > 0 && a[i] * 1ll * j - b[i] <= n) res += fr[j][a[i] * j - b[i]];
		}
	}
	printf("%lld\n", res);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
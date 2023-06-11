#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 500 + 5;

int n, m;
char s[N][N];

void solve() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
	int a, b, c, d;
	for (int i = 1; i <= n; i++) {
		bool f = 0;
		for (int j = 1; j <= m; j++) if (s[i][j] == '#') f = 1;
		if (f) {
			a = i;
			break;
		}
	}
	for (int i = n; i; i--) {
		bool f = 0;
		for (int j = 1; j <= m; j++) if (s[i][j] == '#') f = 1;
		if (f) {
			b = i;
			break;
		}
	}
	for (int i = 1; i <= m; i++) {
		bool f = 0;
		for (int j = 1; j <= n; j++) if (s[j][i] == '#') f = 1;
		if (f) {
			c = i;
			break;
		}
	}
	for (int i = m; i; i--) {
		bool f = 0;
		for (int j = 1; j <= n; j++) if (s[j][i] == '#') f = 1;
		if (f) {
			d= i;
			break;
		}
	}
	for (int i = a; i <= b; i++) {
		for (int j = c; j <= d; j++) {
			if (s[i][j] == '.') return printf("%d %d\n", i, j), void();
		}
	}
}

int main() {
	int T = 1;
	while (T--) {
		solve();
	}
	return 0;
}
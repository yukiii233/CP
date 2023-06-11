#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1000 + 5;

int n, m, a[N][N], p[N];

void solve() {
	scanf("%d %d", &n, &m);
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) a[j][i] = ++cnt;
	}
	cnt = 0;
	for (int i = 1; i <= m; i += 2) {
		p[++cnt] = i;
	}
	for (int i = 2; i <= m; i += 2) 
		p[++cnt] = i;
	if (m == 4) swap(p[1], p[2]), swap(p[3], p[4]);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) printf("%d ", a[i][p[j]]);
		puts("");
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
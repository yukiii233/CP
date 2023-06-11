#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e6 + 5;

void solve() {
	int n, m;
	scanf("%d %d", &n, &m);
	if (n != 1 && n <= m) return puts("NO"), void();
	for (int i = 2; i * i <= n; i++) if (n % i == 0) {
		int j = n / i;
		if (m * 1ll * (j - 1) + i >= n) return puts("NO"), void();
		swap(i, j);
		if (m * 1ll * (j - 1) + i >= n) return puts("NO"), void();
		swap(i, j);
	}
	puts("YES");
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
}
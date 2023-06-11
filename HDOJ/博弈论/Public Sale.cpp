#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

int n, m;

void solve() {
	int cnt = m / (n + 1);
	bool flag = 0;
	while (cnt) {
		if (m - cnt * (n + 1) <= n && m - cnt * (n + 1) >= 1) flag = 1, printf("%d ", m - cnt * (n + 1));
		cnt--;
	}
	for (int i = m; i <= n; i++) printf("%d ", i), flag = 1;
	if (!flag) printf("none");
	puts("");
}

int main() {
	while (scanf("%d %d", &m, &n) == 2) {
		solve();
	}
	return 0;
}
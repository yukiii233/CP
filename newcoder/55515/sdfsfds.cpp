#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int x = c - a, y = d - b;
	if (x > y) swap(x, y);
	if (x == 1 && y == 1) return puts("lose"), void();
	bool f = (y - x) % 4 != 0;
	f ? puts("win") : puts("lose");
}

int main() {
	// init();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	// for (int i = 1; i <= 10; i++) {
	// 	for (int j = i; j <= 10; j++) {
	// 		memset(dp, 0, sizeof dp);
	// 		if (dfs(i, j, 0) == 1) printf("%d %d\n", i, j);
	// 	}
	// }
	//printf("%d\n", dfs(2, 2, 1));
}
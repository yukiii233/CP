#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e6 + 6;

// map<int, int> vis;

// int mex(map<int, bool> &mp) {
// 	for (int i = 0; ; i++) if (!mp.count(i)) {
// 		return i;
// 	}
// 	return 233;
// }
// int dfs(int n) {
// 	if (vis.count(n)) return vis[n];
// 	map<int, bool> mp;
// 	for (int i = 1; i <= n; i++) {
// 		mp[dfs(n - i)] = 1;
// 	}
// 	for (int i = 1; i < n; i++) {
// 		mp[dfs(i) ^ dfs(n - i)] = 1;
// 	}
// 	return vis[n] = mex(mp);
// }

int n;

void solve() {
	scanf("%d", &n);
	int xo = 0;
	int Bigger = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		int sg = x;
		if (x % 4 == 0) sg--;
		if (x % 4 == 3) sg++;
		xo ^= sg;
		if (sg > 1) Bigger = 1;
	}
	bool f = 1;
	(xo == 0 && Bigger == 0) || (xo > 0 && Bigger == 1) ? puts("Alice") : puts("Bob");
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
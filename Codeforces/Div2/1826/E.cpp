#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;

int n, m, val[5005], a[5005], p[5005], in[5005];
ll dp[5005];
bitset<5005> res[5005], trans, pre[5005];

ll dfs(int u) {
	if (dp[u]) return dp[u];
	dp[u] = val[u];
	for (int i = 1; i <= n; i++) if (res[u][i] == 1) {
		dp[u] = max(dp[u], dfs(i) + val[u]);
	}
	return dp[u];
}

void solve() {
	cin >> m >> n;
	for (int i = 1; i <= n; i++) cin >> val[i];
	for (int i = 1; i <= n; i++) res[i].set();
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) cin >> a[j];
		iota(p + 1, p + n + 1, 1);
		sort(p + 1, p + n + 1, [](int x, int y) {
			return a[x] < a[y];
		});
		trans.reset();
		for (int j = 1; j <= n; j++) {
			if (j != 1 && a[p[j]] == a[p[j - 1]]) {
				pre[p[j]] = pre[p[j - 1]];
				trans.set(p[j]);
			} else {
				pre[p[j]] = trans;
				trans.set(p[j]);
			}
		}
		for (int j = 1; j <= n; j++) res[j] &= pre[j];
	}
	trans.reset();
	for (int i = 1; i <= n; i++) trans |= res[i];
	for (int i = 1; i <= n; i++) dfs(i);
	cout << *max_element(dp + 1, dp + n + 1) << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	while (T--) {
		solve();
	}
}
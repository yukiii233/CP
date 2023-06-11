#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

void solve() {
	int n, m, r;
	scanf("%d %d %d", &n, &m, &r);
	vector<vector<vector<bool>>> f(n + 1, vector<vector<bool>>(m + 1, vector<bool>(r + 1, 1))), dp(n + 1, vector<vector<bool>>(m + 1, vector<bool>(r + 1, 0)));
	for (int i = 1; i <= r; i++) {
		int t, d, coor;
		scanf("%d %d %d", &t, &d, &coor);
		if (d == 1) {
			for (int j = 0; j <= m; j++) if (t - coor - j >= 0 && t - coor - j <= r) {
				f[coor][j][t - coor - j] = 0;
			}
		} else {
			for (int j = 0; j <= n; j++) if (t - coor - j >= 0 && t - coor - j <= r) {
				f[j][coor][t - coor - j] = 0;
			}
		}
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			for (int k = 0; k <= r; k++) {
				dp[i][j][k] = !(i || j || k);
				if (i && dp[i - 1][j][k]) dp[i][j][k] = 1;
				if (j && dp[i][j - 1][k]) dp[i][j][k] = 1;
				if (k && dp[i][j][k - 1]) dp[i][j][k] = 1;
				if (f[i][j][k] == 0) dp[i][j][k] = 0;
			}
		}
	}
	int ans = -1;
	for (int i = r; i >= 0; i--) if (dp[n][m][i]) ans = n + m + i;
	printf("%d\n", ans);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
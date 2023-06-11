#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

int n, b[N], a[4], dp[N][2][2][2];

int getv(int i, int j, int k, int l) {
	int res = 0;
	if (j) res += a[3];
	if (k) res += a[2];
	if (l) res += a[1];
	return res;
}

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
		memset(dp[i], 0, sizeof dp[i]);
	for (int i = 1; i <= 3; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	dp[1][0][0][1] = a[1];
	for (int i = 2; i <= n; i++) {
		for (int cur = 0; cur < 8; cur++) {
			int j = (cur >> 2) & 1, k = (cur >> 1) & 1, l = cur & 1, cnt = j + k + l;
			if (cnt > b[i] || i <= 2 && j == 1 || i == 1 && k == 1) continue;
			int able = 4 + ((!j) << 1) + (!k);
			for (int nxt = 0; nxt < 8; nxt++) {
				int sta = nxt & able;
				int j1 = (sta >> 2) & 1, k1 = (sta >> 1) & 1, l1 = sta & 1, cnt1 = j1 + k1 + l1;
				if (cnt1 > b[i - 1] || i <= 3 && j1 == 1 || i <= 2 && k1 == 1) continue;
				dp[i][j][k][l] = max(dp[i][j][k][l], getv(i, j, k, l) + dp[i - 1][j1][k1][l1]);
			}
		}
	}
	int res = 0;
	for (int j = 0; j < 2; j++) {
		for (int k = 0; k < 2; k++) {
			for (int l = 0; l < 2; l++) {
				printf("%d %d %d %d\n", j, k, l, dp[2][j][k][l]);
			}
		}
	}
	printf("%d\n", res);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 5;
int n, w;
int a[N], dp[3005][3005];

void solve() {
	scanf("%d %d", &n, &w);
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		for (int j = 1; j <= num; j++) scanf("%d", &a[j]);
		for (int k = 1; k <= num; k++) {
			for (int j = a[k]; j <= w; j++) 
				dp[i][j] += dp[i - 1][j - a[k]];
		}
	}
	printf("%d\n", dp[n][w]);
}

int main() {
	int T = 1;
	while (T--) {
		solve();
	}
}
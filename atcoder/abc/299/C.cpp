#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 2e5 + 5;

int n, dp[N];
char s[N];

void solve() {
	scanf("%d %s", &n, s + 1);
	for (int i = 1; i <= n; i++) {
		if (s[i] == '-') dp[i] = 0;
		else dp[i] = dp[i - 1] + 1;
	}
	int res = -1;
	for (int i = 1; i <= n; i++) if (s[i] == 'o') {
		if (dp[i] != i || (i != n && s[i + 1] == '-')) res = max(res, dp[i]);
	}
	printf("%d\n", res);
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
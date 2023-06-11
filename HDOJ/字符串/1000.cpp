#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e3 + 5;

char s[N], t[N + N];
int k[N + N], n, m, dp[N + N];

void solve() {
    k[1] = 0;
	for (int i = 2; i <= n + m + 1; i++) {
		dp[i] = 0;
		int j = k[i - 1];
		while (j != 0 && t[i] != t[j + 1]) j = k[j];
		if (t[i] == t[j + 1]) k[i] = j + 1;
		else k[i] = 0;
	}
	for (int i = m + 2; i <= n + m + 1; i++) {
		dp[i] = dp[i - 1];
		if (k[i] == m) dp[i] = max(dp[i], dp[i - m] + 1);
	}
	printf("%d\n", dp[n + m + 1]);
}

int main() {
    while (scanf("%s", s + 1) == 1 && s[1] != '#') {
        scanf("%s", t + 1);
        n = strlen(s + 1), m = strlen(t + 1);
        t[m + 1] = '#';
        for (int i = m + 2; i < m + 2 + n; i++) t[i] = s[i - m - 1];
        solve();
    }
    return 0;
}
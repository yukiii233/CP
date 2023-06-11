#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 5e5 + 5;

int n, a[N], dp[N], f[N];

void solve() {
	cin >> n;
	for (int i = 1; i < n; i++) cin >> a[i];
	dp[1] = a[1] == 0;
	f[1] = 1;
	for (int i = 2; i < n; i++) {
		f[i] = (f[i - 1] * 1ll * (i - 1 - a[i - 1])) % mod;
		dp[i] = (dp[i - 1] * 1ll * i % mod + f[i] * (a[i] == 0)) % mod;
	}
	for (int i = 1; i < n; i++) cout << dp[i] << " \n"[i == n - 1];
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}
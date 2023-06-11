#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

void solve() {
	int n;
	cin >> n;
	int x = n / 5;
	int res = n - x * 5, ans = x * 5;
	if (ans != 100 && (x + 1) * 5 - n < res) {
		ans += 5;
	}
	cout << ans << '\n';
}

int main() {
	int T = 1;
	while (T--) {
		solve();
	}
	return 0;
}
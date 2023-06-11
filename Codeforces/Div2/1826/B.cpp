#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

int n;
int a[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int res = 0;
	for (int i = 1; i <= n; i++) {
		int j = n - i + 1;
		if (j <= i) break;
		res = __gcd(res, abs(a[i] - a[j]));
	}
	cout << res << '\n';
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}
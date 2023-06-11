#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

int n, a[N];
bitset<1000005> bs;

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], bs[a[i]] = 1;
	sort(a + 1, a + n + 1, greater<int>());
	for (int i = 1; i <= n; i++) {
		map<int, bool> r;
		int x = a[i];
		for (int j = 2; j * j <= x; j++) if (x % j == 0) {
			while (x % j == 0) x /= j;
			r[j] = 1;
		}
		if (x != 1) r[x] = 1;
		bool f = 1;
		for (auto [x, v] : r) {
			if (bs[x] == 0) {
				f = 0;
				break;
			}
		}
		if (f) return cout << a[i] << '\n', void();
	}
	cout << -1 << '\n';
}

int main() {
	int T = 1;
	while (T--) {
		solve();
	}
	return 0;
}
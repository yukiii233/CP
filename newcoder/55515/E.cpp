#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll x, y;



void solve() {
	cin >> x >> y;
	ll res = 0;
	for (ll a = 1; a <= y * 2; a++) {
		if (2 * y * y - a * a <= 0) break;
		ll q = 2 * y * y - a * a;
		q = sqrt(q);
		ll qq = q;
		for (ll i = max(1ll, qq - 2); i <= qq + 2; i++) {
			if (i * i <= 2 * y * y - a * a) q = i;
		}
		if (x - 2 * a == 0) continue;
		if (x - 2 * a < 0) {
			ll p = (a * x - 1) / (2 * a - x) + 1;
			res += max(0ll, q - p + 1);
		}
	}
	cout << res << '\n';
}

int main() {
	int T = 1;
	while (T--) {
		solve();
	}
}
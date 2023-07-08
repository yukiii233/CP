#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = 1e18;
const int mod = 998244353;
const int N = 1e5 + 5;

ll n;
map<ll, bool> mp;

void solve() {
	scanf("%lld", &n);
	if (mp.count(n)) {
		puts("YES");
	} else {
		ll l = 2, r = 1e9;
		while (l <= r) {
			ll mid = (l + r) >> 1;
			if (mid * mid + mid + 1 == n) return puts("YES"), void();
			if (mid * mid + mid + 1 > n) r = mid - 1;
			else l = mid + 1;
		}
		puts("NO");
	}
}

int main() {
	for (ll k = 2; k < N; k++) {
		__int128 n = k, sum = k + 1;
		while (true) {
			if (sum > inf - n * k) break;
			n *= k;
			sum += n;
			mp[sum] = 1;
		}
	}
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
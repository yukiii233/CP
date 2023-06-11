#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define int long long
const int mod = 998244353;
const int N = 20000 + 5;

int n, a[N], b[N], c[N];

bool check(int mid) {
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] > mid) continue;
		res += (min(mid, b[i]) - a[i]) / c[i] + 1;
	}
	return res & 1;
}

void solve() {
	int l = 1, r = 0, ans = -1;
    for (int i = 1; i <= n; i++)
    	scanf("%lld %lld %lld", &a[i], &b[i], &c[i]), r = max(b[i], r);
    while (l <= r) {
    	int mid = (l + r) >> 1;
    	if (check(mid)) r = mid - 1, ans = mid;
    	else l = mid + 1;
    }
    if (ans == -1) return puts("DC Qiang is unhappy."), void();
    int res = 0;
    for (int i = 1; i <= n; i++)
    	if (a[i] <= ans && ans <= b[i] && ans % c[i] == a[i] % c[i]) res++;
    printf("%lld %lld\n", ans, res);
}

signed main() {
    while (~scanf("%lld", &n)) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;
const int N = 2e5 + 5;

int a[N], b[N], sum[N], pro[N], cnt;

int fpow(int a, int b) {
	int res = 1;
	for (; b; b >>= 1, a = a * 1ll * a % mod) if (b & 1) res = res * 1ll * a % mod;
	return res; 
}

void solve() {
	int n, m;
	map<int, int> mp;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		mp[x]++;
	}
	cnt = 0;
	pro[0] = 1;
	for (auto [x, y] : mp) {
		a[++cnt] = x;
		b[cnt] = y;
		sum[cnt] = sum[cnt - 1] + y;
		pro[cnt] = pro[cnt - 1] * 1ll * y % mod;
	}
	int res = 0;
	for (int i = 1; i <= cnt; i++) {
		int pos = lower_bound(a + 1, a + cnt + 1, a[i] + m) - a - 1;
		if (pos - i + 1 < m) continue;
		pos = i + m - 1;
		res = (res + pro[pos] * 1ll * fpow(pro[i - 1], mod - 2) % mod) % mod;
	}
	printf("%d\n", res);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
}
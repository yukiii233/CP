#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e6 + 5;

int n, m, d[N + N];
char s[N], t[N + N];
ll a[N], sum[N];

bool check(int l, int r) {
	if ((r - l + 1) & 1) {
		int k = d[l + r] - 1;
		return k >= r - l + 1;
	} else {
		int k = d[l + r] - 1;
		return k >= r - l + 1;
	}
	return 0;
}
ll value(int l, int r) {
	return check(l, r) ? sum[r] - sum[l - 1] : 0;
}

void solve() {
    for (int i = 1; i <= 26; i++) scanf("%lld", &a[i]);
    scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[s[i] - 'a' + 1];
	for (int i = 1; i <= n; i++) t[i * 2] = s[i], t[i * 2 - 1] = '#';
    t[n * 2 + 1] = '#';
	m = n * 2 + 1;
	for (int i = 1, l = 0, r = 0; i <= m; i++) {
		int k = i <= r ? min(d[r - i + l], r - i + 1) : 1;
		while (i + k <= m && i - k >= 1 && t[i + k] == t[i - k]) k++;
		d[i] = k--;
		if (i + k > r) r = i + k, l = i - k;
	}
	ll res = 0;
	for (int i = 1; i < n; i++) {
		res = max(res, value(1, i) + value(i + 1, n));
	}
	printf("%lld\n", res);
	//for (int i = 1; i <= n; i++) printf("%d %d\n", i, d[i * 2 - 1] / 2);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

int n, m;
int a[N], b[N], s[N];

void solve() {
	scanf("%d %d", &n, &m);
	fill(b + 1, b + m + 1, 0);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int l = 0, r = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] > 0) b[a[i]] = 1;
		else if (a[i] == -1) l++;
		else r++;
	}
	for (int i = 1; i <= m; i++) s[i] = s[i - 1] + b[i];
	int res = max(l, r);
	for (int i = 1; i <= m; i++) if (b[i]) {
		res = max(res, min(i - s[i], l) + min(m - i - (s[m] - s[i]), r) + s[m]);
	}
	res = max(res, s[m] - b[1] + r);
	res = max(res, s[m] - b[m] + l);
	printf("%d\n", min(res, m));
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
}
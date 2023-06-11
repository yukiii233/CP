#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 2e5 + 5;

int n, a[N], ans[N];
char s[N];

void solve() {
	int sa = 0, sb = 0;
	scanf("%d %s", &n, s + 1);
	for (int i = 1; i <= n; i++) a[i] = (s[i] == '(' ? 1 : -1);
	for (int i = 1; i <= n; i++) {
		if (a[i] > 0) {
			if (sb < 0) {
				ans[i] = 2;
				sb++;
			} else {
				ans[i] = 1;
				sa++;
			}
		} else {
			if (sa > 0) {
				ans[i] = 1;
				sa--;
			} else {
				ans[i] = 2;
				sb--;
			}
		}
	}
	int cnt = 1;
	for (int i = 1; i < n; i++) if (ans[i] != ans[i + 1]) {
		cnt = 2;
		break;
	}
	if (sa != 0 || sb != 0) puts("-1");
	else {
		printf("%d\n", cnt);
		for (int i = 1; i <= n; i++) printf("%d%c", cnt == 1 ? 1 : ans[i], " \n"[i == n]);
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
}
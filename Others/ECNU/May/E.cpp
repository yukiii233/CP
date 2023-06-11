#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 202305 + 5;

int n, m, L, R, pre[N], b[N];
bool have0[N];

struct node {
	int op, t, s;
} a[N];

int fpow(int a, int b) {
	int res = 1;
	for (; b; b >>= 1, a = a * 1ll * a % mod) if (b & 1) res = res * 1ll * a % mod;
	return res;
}

void solve() {
	scanf("%d %d", &m, &n);
	scanf("%d %d", &L, &R);
	char ss[7];
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%s %d", ss + 1, &x);
		if (ss[1] == 'a') {
			a[i] = {1, x, a[i - 1].s + a[i - 1].op};
		} else a[i] = {-1, x, a[i - 1].s + a[i - 1].op};
	}
	for (int i = 1; i <= n; i++) if (a[i].op == -1) {
		b[a[i].t] = a[i].s;
	}
	int res = 0;
	// for (int i = 1; i <= n; i++) if (a[i].op == 1) {
	// 	int no = 1;
	// 	for (int j = a[i].t + L; j <= min(N - 5, a[i].t + R); j++) if (b[j]) {
	// 		int ye = no * 1ll * fpow(b[j], mod - 2) % mod;
	// 		res = (res + ye) % mod;
	// 		no = ye * 1ll * (b[j] - 1) % mod;
	// 	}
	// }
	for (int i = 1; i <= n; i++) {

	}
	printf("%d\n", res);
}

int main() {
	int T = 1;
	while (T--) {
		solve();
	}
}
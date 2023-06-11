#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 3e5 + 5;

int n, a[N];

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	n = unique(a + 1, a + n + 1) - a - 1;
	int res = n;
	for (int i = 1; i + 2 <= n; i++) {
		res -= (a[i] < a[i + 1] && a[i + 1] < a[i + 2]);
		res -= (a[i] > a[i + 1] && a[i + 1] > a[i + 2]);
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
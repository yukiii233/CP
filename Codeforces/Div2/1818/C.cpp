#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 5;
int n, a[N], sum[N];

void solve() {
	int Q;
	cin >> n >> Q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1];
		if (i > 1 && i < n) sum[i] += a[i] <= a[i - 1] && a[i] >= a[i + 1]; 
	}
	while (Q--) {
		int l, r;
		cin >> l >> r;
		cout << r - l + 1 - (l == r ? 0 : (sum[r - 1] - sum[l])) << '\n';
	}
}

int main() {
	int T = 1;
	while (T--) {
		solve();
	}
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1005, M = 10000;
int n, k;
int a[N], b[N], s[M];

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		s[a[i] * 70 + b[i] * 20]++;
	}
	for (int i = 1; i < M; i++) s[i] += s[i - 1];
	for (int i = 1; i <= n; i++) {
		if (n - s[a[i] * 70 + b[i] * 20 + 1000] + 1 <= k) {
			cout << "Yes\n";
		} else cout << "No\n";
	}
}

int main() {
	int T = 1;
	while (T--) {
		solve();
	}
}
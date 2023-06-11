#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

int n, a[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int ans = -1;
	for (int i = 1; i <= n; i++) if (i == n || a[i + 1] != a[i]) {
		int x = n - i;
		if (x >= a[i] && (i == n || x < a[i + 1])) ans = x;
	}
	cout << ans << '\n';
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}
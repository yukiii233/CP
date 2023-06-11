#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

int n, p[N];

bool check() {
	for (int len = 2; len <= n; len++) {
		for (int i = 1; i + len - 1 <= n; i++) {
			int j = i + len - 1;
			int sum = 0;
			for (int k = i; k <= j; k++) sum += p[k];
			if (sum % len == 0) return 0;
		}
	}
	return 1;
}

void solve() {
	// n = 10;
   	// iota(p + 1, p + n + 1, 1);
   	// do {
   	// 	if (check()) for (int i = 1; i <= n; i++) printf("%d%c", p[i], " \n"[i == n]);
   	// } while (next_permutation(p + 1, p + n + 1));
	cin >> n;
	if (n == 1) return cout << "1\n", void();
	else if (n & 1) return cout << "-1\n", void();
	else {
		for (int i = 1; i <= n; i += 2) {
			cout << i + 1 << ' ' << i << ' ';
		}
		cout << '\n';
	}
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
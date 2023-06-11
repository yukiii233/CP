#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
int x, y;
bool f1(int a, int b) {
	return x * (a + b) <= 2 * a * b;
}
bool f2(int a, int b) {
	return 4 * a * a * b * b <= a * b * (a + b) * (a + b);
}
bool f3(int a, int b) {
	return 4 * a * b <= (a + b) * (a + b);
}
bool f4(int a, int b) {
    return (a + b) * (a + b) <= 2 * (a * a + b * b);
}
bool f5(int a, int b) {
	return a * a + b * b <= y * y * 2;
}

void solve() {
	int res = 0;
	cin >> x >> y;
	for (int i = 1; i <= y * 2; i++) {
		for (int j = 1; j <= y * 2; j++) {
			if (f1(i, j) && f2(i, j) &&f3(i, j) &&f4(i, j) &&f5(i, j)) {
				res++;
			}
		}
	}	
	cout << res << '\n';
}

signed main() {
	int T = 1;
	while (T--) {
		solve();
	}
}
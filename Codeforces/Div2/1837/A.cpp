#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

void solve() {
	int x, k;
	scanf("%d %d", &x, &k);
	if (x % k == 0) {
		printf("%d\n%d %d\n", 2, x + 1, -1);
	} else {
		printf("%d\n%d\n", 1, x);
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
}
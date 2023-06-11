#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

void solve() {
	double m, x, a, b;
	scanf("%lf %lf %lf %lf", &m, &x, &a, &b);
	int k = floor(m / x);
	double res;
	if (k >= b) res = 0;
	else res = (b * x - a - m > 0 ? (b / (a + m)) : ((b - k) / (a + m - k * x)));
	printf("%.9lf\n", 1.0 / (1.0 + res));
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
}
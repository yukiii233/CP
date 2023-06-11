#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

double n;

void solve() {
	double res;
	scanf("%lf %lf", &n, &res);
	printf("%lf\n", res / log(n));
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
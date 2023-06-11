#include <cstdio>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

void solve() {
	int n, m;
	scanf("%d %d", &n, &m);
	(n % (m + 1) == 0) ? puts("second") : puts("first");
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
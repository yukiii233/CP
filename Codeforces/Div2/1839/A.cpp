#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

int n, k;

void solve() {
	scanf("%d %d", &n, &k);
	int sa = 0, sb = 0, la = 0, lb = n + 1;
	vector<bool> v(n + 1);
	for (int i = 1; i <= n; i++) {
		int x = (i - 1) / k + 1; 
		la++, lb--;
		sa += v[la], sb += v[lb];
		if (sa < x) v[la] = 1, sa++, sb += la == lb;
		if (sb < x) v[lb] = 1; sb++;
	}
	printf("%d\n", sa);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
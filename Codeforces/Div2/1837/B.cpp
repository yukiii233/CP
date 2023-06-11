#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 505;

int n;
char s[N];

void solve() {
	scanf("%d %s", &n, s + 1);
	int p = 0, len = 0;
	for (int i = 1; i <= n; i++) {
		int re = 1;
		while (i != n && s[i] == s[i + 1]) i++, re++;
		len = max(len, re);
	}
	printf("%d\n", len + 1);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
}
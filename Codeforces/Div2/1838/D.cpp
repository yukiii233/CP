#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 2e5 + 5;

int n, q;
char s[N];

void solve() {
	scanf("%d %d %s", &n, &q, s + 1);
	set<int> se;
	for (int i = 1; i <= n; i++) {
		if (i % 2 && s[i] == ')') se.emplace(i);
		if (i % 2 == 0 && s[i] == '(') se.emplace(i);
	}
	while (q--) {
		int x;
		scanf("%d", &x);
		if (n & 1) {
			puts("NO");
			continue;
		}
		if (x % 2 && s[x] == ')') se.erase(x);
		if (x % 2 == 0 && s[x] == '(') se.erase(x);
		s[x] = (s[x] == ')' ? '(' : ')');
		if (x % 2 && s[x] == ')') se.emplace(x);
		if (x % 2 == 0 && s[x] == '(') se.emplace(x);
		if (se.empty()) {
			puts("YES");
			continue;
		}
		if (*se.begin() & 1) {
			puts("NO");
		} else if (*se.rbegin() % 2 == 0) {
			puts("NO");
		} else puts("YES");
	}
}

int main() {
	int T = 1;
	while (T--) {
		solve();
	}
	return 0;
}
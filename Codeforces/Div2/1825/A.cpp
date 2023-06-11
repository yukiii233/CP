#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 50 + 5;

int n;
char s[N];

void solve() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	int res = -1;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) if (s[i] != s[j]) {
			res = max(res, j - i + 1 + 2 * min(n - j, i - 1));
		}
	printf("%d\n", res);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
}
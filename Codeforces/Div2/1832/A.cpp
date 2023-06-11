#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

int n;
char s[N];

void solve() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	bool p = 0;
	set<char> se;
	for (int i = 1; i + i <= n; i++) se.insert(s[i]);
	se.size() == 1 ? puts("NO") : puts("YES");
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
}
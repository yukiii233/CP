#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 3e5 + 5;

int n;
char s[N];

void solve() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	if (s[n] == '?') s[n] = '1';
	for (int i = n - 1; i; i--) if (s[i] == '?') {
		s[i] = s[i + 1];
	}
	printf("%s\n", s + 1);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
}
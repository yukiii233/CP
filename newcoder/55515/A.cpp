#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
char s[200005];
bool a[200005];

void solve() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	int cnt = 0;
	for (int i = 1; i <= n; i++) cnt += s[i] == '1', a[i] = s[i] == '1';
		if (cnt & 1) return puts("-1"), void();
	int res = 0;
	for (int i = 1; i < n; i++) {
		if (s[i] == '1' && s[i + 1] == '1') {
			res++;
			s[i] = s[i + 1] = '0';
		}
	}
	int j = 1;
	for (int i = 1; i < n; i++) {
		if (s[i] == '1') {
			if (s[i + 1] == '1') {
				res += 1;
				s[i] = s[i + 1] = '0';
				continue;
			}
			if (i == n - 1 || s[i + 2] == '1') return puts("-1"), void();
			s[i + 1] = s[i + 2] = '1';
			s[i] = '0';
			s[i + 1] = '0';
			res += 2;
		}
		//printf("%d %s\n", i, s + 1);
	}
	if (s[n] == '1') res = -1;
	printf("%d\n", res);
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}
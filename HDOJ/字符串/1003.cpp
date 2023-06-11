#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

int n, k[N];
char s[N], t[N], a[N], r[N];

void solve() {
	scanf("%s %s", a + 1, s + 1);
    k[1] = 0;
    n = strlen(s + 1);
    for (int i = 1; i <= 26; i++) r[a[i]] = 'a' + i - 1;
    for (int i = 1; i <= n; i++) t[i] = a[s[i] - 'a' + 1];
	for (int i = 2; i <= n; i++) {
		int j = k[i - 1];
		while (j != 0 && t[i] != s[j + 1]) j = k[j];
		if (t[i] == s[j + 1]) k[i] = j + 1;
		else k[i] = 0;
	}
	while (k[n] + k[n] > n) k[n] = k[k[n]];
	printf("%s", s + 1);
	for (int i = 1 + k[n]; i <= n - k[n]; i++) putchar(r[s[i]]);
	puts("");
	//printf("%d\n", k[n]);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
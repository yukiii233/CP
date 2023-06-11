#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 110000 + 5;

int n, m, d[N * 2];
char s[N], t[N * 2];

void solve() {
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++) t[i * 2] = s[i], t[i * 2 - 1] = '#';
    t[n * 2 + 1] = '#';
	m = n * 2 + 1;
	for (int i = 1, l = 0, r = 0; i <= m; i++) {
		int k = i <= r ? min(d[r - i + l], r - i + 1) : 1;
		while (i + k <= m && i - k >= 1 && t[i + k] == t[i - k]) k++;
		d[i] = k--;
		if (i + k > r) r = i + k, l = i - k;
	}
	printf("%d\n", *max_element(d + 1, d + m + 1) - 1);
}

int main() {
    while (scanf("%s", s + 1) != EOF) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 10007;
const int N = 200000 + 5;

int n, k[N], ans[N];
char s[N];

void solve() {
	scanf("%d", &n);
	scanf("%s", s + 1);
    k[1] = 0;
	fill(ans + 1, ans + n + 1, 0);
	for (int i = 2; i <= n; i++) {
		int j = k[i - 1];
		while (j != 0 && s[i] != s[j + 1]) j = k[j];
		if (s[i] == s[j + 1]) k[i] = j + 1;
		else k[i] = 0;
	}
	for (int i = 1; i <= n; i++) ans[k[i]]++;
	for (int i = n; i >= 1; i--) ans[k[i]] = (ans[k[i]] + ans[i]) % mod;
	for (int i = 1; i <= n; i++) ans[i]++;
	int res = 0;
	for (int i = 1; i <= n; i++) res = (res + ans[i]) % mod;
	printf("%d\n", res);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
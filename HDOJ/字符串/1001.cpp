#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N =  50005;

char s[N + N], t[N + N];
int k[N + N], n, m;

void solve() {
    k[1] = 0;
	for (int i = 2; i <= n + m + 1; i++) {
		int j = k[i - 1];
		while (j != 0 && s[i] != s[j + 1]) j = k[j];
		if (s[i] == s[j + 1]) k[i] = j + 1;
		else k[i] = 0;
	}
	for (int i = 1; i <= k[n + m + 1]; i++) putchar(s[i]);
	if (k[n + m + 1] != 0) putchar(' ');
	printf("%d\n", k[n + m + 1]);
}

int main() {
    while (scanf("%s %s", s + 1, t + 1) != EOF) { 
        n = strlen(s + 1), m = strlen(t + 1);
        s[n + 1] = '#';
        for (int i = n + 2; i < m + 2 + n; i++) s[i] = t[i - n - 1];
        solve();
    }
    return 0;
}
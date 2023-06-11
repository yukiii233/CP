#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 20000 + 5;

int n, m, d[N * 2];
char s[N], t[N * 2];

bool check(int l, int r) {
	if (l > r) return 0;
	if ((r - l + 1) & 1) {
		int k = d[l + r] - 1;
		return k >= r - l + 1;
	} else {
		int k = d[l + r] - 1;
		return k >= r - l + 1;
	}
	return 0;
}

void solve() {
	scanf("%s", s + 1);
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
   	for (int i = 1; i <= n; i++) if (d[i * 2] / 2 == i) {
   		int ir = i + i - 1;
   		for (int j = n; j > ir; j--) if (d[j * 2] / 2 == n - j + 1) {
   			int lj = j - (n - j);
   			if (check(ir + 1, lj - 1)) return puts("Yes"), void();
   		}
   	}
   	for (int i = 2; i <= n; i++) if (d[i * 2 - 1] / 2 == i - 1) {
   		int ir = i + i - 2;
   		for (int j = n; j > ir; j--) if (d[j * 2] / 2 == n - j + 1) {
   			int lj = j - (n - j);
   			if (check(ir + 1, lj - 1)) return puts("Yes"), void();
   		}
   	}
   	for (int i = 1; i <= n; i++) if (d[i * 2] / 2 == i) {
   		int ir = i + i - 1;
   		for (int j = n; j > ir; j--) if (d[j * 2 - 1] / 2 == n - j + 1) {
   			int lj = j - (n - j) - 1;
   			if (check(ir + 1, lj - 1)) return puts("Yes"), void();
   		}
   	}
   	for (int i = 2; i <= n; i++) if (d[i * 2 - 1] / 2 == i - 1) {
   		int ir = i + i - 2;
   		for (int j = n; j > ir; j--) if (d[j * 2 - 1] / 2 == n - j + 1) {
   			int lj = j - (n - j) - 1;
   			if (check(ir + 1, lj - 1)) return puts("Yes"), void();
   		}
   	}
   	puts("No");
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
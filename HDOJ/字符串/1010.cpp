#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

int n, m, s[N], t[N * 2], d[N * 2], up[N];

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    	scanf("%d", &s[i]);
    m = n * 2 + 1;
    for (int i = 1; i <= n; i++)
    	t[i * 2] = s[i], t[i * 2 - 1] = -1;
   	t[n * 2 + 1] = -1;
   	for (int i = 1, l = 0, r = 0; i <= m; i++) {
   		int k = i <= r ? min(d[r - i + l], r - i + 1) : 1;
   		while (i + k <= m && i - k >= 1 && t[i + k] == t[i - k]) k++;
   		d[i] = k--;
   		if (i + k > r) r = i + k, l = i - k;
   	}
   	for (int i = 1; i <= n; i++) {
   		if (s[i] >= s[i - 1]) up[i] = up[i - 1] + 1;
   		else up[i] = 1;
   	}
   	int res = 1;
   	for (int i = 2; i < n; i++) {
   		int k = min(up[i], d[i * 2] / 2);
   		res = max(res, k * 2 - 1);
   		k = min(d[i * 2 - 1] / 2, up[i - 1]);
   		res = max(res, k * 2);
   	}
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
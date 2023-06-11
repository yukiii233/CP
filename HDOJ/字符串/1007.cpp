#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1000000007;
const int N = 1e6 + 5;

int n, m, d[N * 2];
char s[N], t[N * 2];
ll cnt[N], L[N], R[N], sum[N];

void solve() {
   	n = strlen(s + 1);
   	for (int i = 1; i <= n; i++) t[i * 2] = s[i], t[i * 2 - 1] = '#', L[i] = R[i] = cnt[i] = sum[i] = 0;
    t[n * 2 + 1] = '#';
   	m = n * 2 + 1;
   	for (int i = 1, l = 0, r = 0; i <= m; i++) {
   		int k = i <= r ? min(d[r - i + l], r - i + 1) : 1;
   		while (i + k <= m && i - k >= 1 && t[i + k] == t[i - k]) k++;
   		d[i] = k--;
   		if (i + k > r) r = i + k, l = i - k;
   	}
   	for (int i = 1; i <= n; i++) {
   		int k = d[i * 2] / 2;
   		cnt[i]++;
   		cnt[i + k]--;
   		sum[i] += 2 * i;
   		sum[i + k] -= 2 * i;
   	}
   	for (int i = 1; i <= n; i++) {
   		cnt[i] += cnt[i - 1];
   		sum[i] += sum[i - 1];
   		L[i] += sum[i] - i * cnt[i];
   	}
   	for (int i = 1; i <= n; i++) cnt[i] = sum[i] = 0;
   	for (int i = 1; i <= n; i++) {
   		int k = d[i * 2 - 1] / 2;
   		cnt[i]++;
   		cnt[i + k]--;
   		sum[i] += 2 * i;
   		sum[i + k] -= 2 * i;
   	}
   	for (int i = 1; i <= n; i++) {
   		cnt[i] += cnt[i - 1];
   		sum[i] += sum[i - 1];
   		L[i] += sum[i] - i * cnt[i] - cnt[i];
   	}
   	for (int i = 1; i <= n; i++) cnt[i] = sum[i] = 0;
   	for (int i = 1; i <= n; i++) {
   		int k = d[i * 2] / 2;
   		cnt[i + 1]--;
   		cnt[i - k + 1]++;
   		sum[i + 1] -= 2 * i;
   		sum[i - k + 1] += 2 * i;
   	}
   	for (int i = 1; i <= n; i++) {
   		cnt[i] += cnt[i - 1];
   		sum[i] += sum[i - 1];
   		R[i] += sum[i] - i * cnt[i];
   	}
   	for (int i = 1; i <= n; i++) cnt[i] = sum[i] = 0;
   	for (int i = 1; i <= n; i++) {
   		int k = d[i * 2 - 1] / 2;
   		cnt[i]--;
   		cnt[i - k]++;
   		sum[i] -= 2 * i;
   		sum[i - k] += 2 * i;
   	}
   	for (int i = 1; i <= n; i++) {
   		cnt[i] += cnt[i - 1];
   		sum[i] += sum[i - 1];
   		R[i] += sum[i] - i * cnt[i] - cnt[i];
   	}
   	ll res = 0;
   	for (int i = 1; i < n; i++) res = (res + (L[i] % mod) * (R[i + 1] % mod)) % mod;
   	printf("%lld\n", (res + mod) % mod);
}

int main() {
    while (scanf("%s", s + 1) != EOF) {
        solve();
    }
    return 0;
}
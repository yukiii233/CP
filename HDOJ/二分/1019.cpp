#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

int n, m, mx[N][20], mn[N][20], a[N];

int qm(int l, int r) {
	int q = 0;
	while ((1 << (q + 1)) <= r - l + 1) q++;
	return max(mx[l][q], mx[r - (1 << q) + 1][q]);
}
int qmi(int l, int r) {
	int q = 0;
	while ((1 << (q + 1)) <= r - l + 1) q++;
	return min(mn[l][q], mn[r - (1 << q) + 1][q]);
}
bool check(int l, int r) {
	return qm(l, r) - qmi(l, r) < m;
}

void solve() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
    	scanf("%d", &a[i]);
    	mx[i][0] = mn[i][0] = a[i];
    }
    for (int j = 1; j < 20; j++) {
    	for (int i = 1; i <= n; i++) {
    		mx[i][j] = max(mx[i][j - 1], mx[min(n, i + (1 << (j - 1)))][j - 1]);
    		mn[i][j] = min(mn[i][j - 1], mn[min(n, i + (1 << (j - 1)))][j - 1]);
    	}
    }
    ll res = 0;
    for (int i = 1; i <= n; i++) {
    	int l = 1, r = i, ans = i;
    	while (l <= r) {
    		int mid = (l + r) >> 1;
    		if (check(mid, i)) r = mid - 1, ans = mid;
    		else l = mid + 1;
    	}
    	res += i - ans + 1;
    	//printf("%d %d\n", ans, i);
    }
    printf("%lld\n", res);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
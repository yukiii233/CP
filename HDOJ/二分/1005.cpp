#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;
int n, a[N], b[N];

bool check(int mid) {
	for (int i = 1; i <= n; i++) b[i] = a[i];
	b[n] += mid;
	for (int i = n - 1; i; i--) {
		if (b[i] - mid >= b[i + 1]) return 0;
		b[i] = min(b[i + 1] - 1, b[i] + mid);
	}
	return 1;
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
    	scanf("%d", &a[i]);
    	if (i > 1) b[i] = a[i] - a[i - 1];
    }
    int l = 0, r = 1e6, ans = -1;
    while (l <= r) {
    	int mid = (l + r) >> 1;
    	if (check(mid)) r = mid - 1, ans = mid;
    	else l = mid + 1;
    }
    static int Case = 0;
    printf("Case #%d:\n", ++Case);
    printf("%d\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 10000 + 5;

int n, k, a[N];

bool check(int mid) {
	int res = 0;
	for (int i = 1; i <= n; i++) res += a[i] / mid;
	return res >= k;
}
int read() {
	int res = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while ((ch <= '9' && ch >= '0') || ch == '.') {
		if (ch != '.') res = res * 10 + ch - '0';
		ch = getchar();
	}
	return res;
}

void solve() {
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	int l = 1, r = *max_element(a + 1, a + n + 1), ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	printf("%.2lf\n", (double)ans / 100.0);
}

int main() {
    // while (scanf("%d %d", &n, &k) == 2) {
    // 	if (n == 0 || k == 0) break;
    //     solve();
    // }
    double x;
    scanf("%lf", &x);
    int y = x * 100.0;
    printf("%d\n", y);
    return 0;
}
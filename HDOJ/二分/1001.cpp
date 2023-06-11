#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const double pi = acos(-1);
const double eps = 1e-5;
const int mod = 998244353;
const int N = 100000 + 5;

int n, m;
double a[N];

bool check(double mid) {
	int res = 0;
	for (int i = 1; i <= n; i++) res += (int)(floor(a[i] / mid));
	return res >= m + 1;
}

void solve() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
    	scanf("%lf", &a[i]);
    	a[i] = a[i] * a[i] * pi;
    }
    double l = 0, r = 1e10, ans = 0.0;
    while (l + eps < r) {
    	double mid = (l + r) / 2.0;
    	if (check(mid)) l = mid, ans = mid;
    	else r = mid;
    }
    printf("%.4lf\n", ans);
}

/* 
25.1327
3.1416
50.2655 
*/

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
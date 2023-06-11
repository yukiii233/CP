#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const double pi = acos(-1);
const double g = 9.8;
const double eps = 1e-12;
const int mod = 998244353;
const int N = 1e5 + 5;

double x, y, v;

double calc(double r) {
    double t = (x / cos(r) / v);
	return v * sin(r) * t - 0.5 * g * t * t;
}

void solve() {
    scanf("%lf %lf %lf", &x, &y, &v);
    double l = 0.0, r = pi / 2.0;
    while (l + eps < r) {
        double lm = l + (r - l) / 3, rm = r - (r - l) / 3;
        if (calc(lm) + eps > calc(rm)) r = rm;
        else l = lm;
    }
    if (calc(l) < y) return puts("-1"), void();
    l = 0.0;
    while (l + eps < r) {
    	double mid = (l + r) / 2.0;
    	if (calc(mid) - eps > y) r = mid;
    	else l = mid;
    }
    printf("%.6lf\n", l);
}
/*
1.561582
-1
-1
*/

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define y2 mikumiku
const int mod = 998244353;
const int N = 1e5 + 5;
const double eps = 1e-8;

double R;

bool query(double x, double y) {
	printf("? %lf %lf\n", x, y);
	fflush(stdout);
	int res;
	scanf("%d", &res);
	return res;
}

int main() {
	scanf("%lf", &R);
	double l = 0.0, r = R + R + 1.0, x1 = 0.0;
	while (l + eps < r) {
		double mid = (l + r) / 2.0;
		if (query(mid, 0)) l = mid + eps, x1 = mid;
		else r = mid - eps;
	}
	l = -R -R - 1, r = 0;
	double x2 = 0.0;
	while (l + eps < r) {
		double mid = (l + r) / 2.0;
		if (query(mid, 0)) r = mid - eps, x2 = mid;
		else l = mid + eps;
	}
	l = 0.0, r = R + R + 1.0;
	double y1 = 0.0;
	while (l + eps < r) {
		double mid = (l + r) / 2.0;
		if (query(0, mid)) l = mid + eps, y1 = mid;
		else r = mid - eps;
	}
	l = -R -R - 1, r = 0;
	double y2 = 0.0;
	while (l + eps < r) {
		double mid = (l + r) / 2.0;
		if (query(0, mid)) r = mid - eps, y2 = mid;
		else l = mid + eps;
	}
	printf("! %.8lf %.8lf\n", (x1 + x2) / 2.0, (y1 + y2) / 2.0);
	fflush(stdout);
	return 0;
} 
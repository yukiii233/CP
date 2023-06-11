#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 100 + 5;
const double eps = 1e-12;
const double pi = acos(-1);

int n;
double a[N], b[N];

bool check(double x) {
    double x2 = x * x;
    double res = acos((b[n] + b[1]- x2) / (2.0 * a[n] * a[1]));
    for (int i = 2; i <= n; i++) res += acos((b[i] + b[i - 1]- x2) / (2.0 * a[i] * a[i - 1]));
    return res + eps < 2.0 * pi;
}
bool check2(double x) {
    double x2 = x * x;
    double res = acos((b[n] + b[1]- x2) / (2.0 * a[n] * a[1]));
    for (int i = 2; i <= n; i++) res += acos((b[i] + b[i - 1]- x2) / (2.0 * a[i] * a[i - 1]));
    return fabs(res - 2.0 * pi) < 1e-5;
}

void solve() {n
    scanf("%d", &n);
    double l = 0.0, r = 0.0, ans = -1.0;
    for (int i = 1; i <= n; i++) scanf("%lf", &a[i]), b[i] = a[i] * a[i];
    r = a[1] + a[n], l = fabs(a[1] - a[n]);
    for (int i = 2; i <= n; i++) r = min(r, a[i] + a[i - 1]), l = max(l, fabs(a[i] - a[i - 1]));
    while (l + eps < r) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
            if (check2(mid)) ans = mid;
        }
        else r = mid;
    }
    static int Case = 0;
    printf("Case %d: ", ++Case);
    ans != -1.0 ? printf("%.3lf\n", ans) : puts("impossible");
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
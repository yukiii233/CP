#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1000 + 5;

void solve() {
    int n; double x;
    double sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &x);
        sum += 1.0 / x;
    }
    sum /= 1.0 * n;
    printf("%.2lf\n", 1.0 / sum);
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
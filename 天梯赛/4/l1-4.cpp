#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

int n;
double m;

void solve() {
    scanf("%d %lf", &n, &m);
    for (int i = 1; i <= n; i++) {
        double x;
        scanf("%lf", &x);
        if (x < m) {
            printf("On Sale! %.1lf\n", x);
        }
    }
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
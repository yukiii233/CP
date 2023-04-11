#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 10 + 5;

int n, m, ans, a[N];
double f[2][N], fac[N];

void solve() {
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int cur = 0;
    memset(f[cur], 0, sizeof f[cur]);
    f[cur][0] = 1;
    for (int i = 1; i <= n; i++) {
        cur ^= 1;
        memset(f[cur], 0, sizeof f[cur]);
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= a[i] && k + j <= m; k++) {
                f[cur][k + j] += f[cur ^ 1][j] / fac[k];
            }
        }
    }
    printf("%.0lf\n", f[cur][m] * fac[m]);
}

int main() {
    fac[0] = 1;
    for (int i = 1; i <= 10; i++) fac[i] = fac[i - 1] * i;
    while (~scanf("%d %d", &n, &m)) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;

int getphi(int x) {
    int res = 1;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            x /= i;
            res *= (i - 1);
            while (x % i == 0) {
                x /= i;
                res *= i;
            }
        }
    }
    if (x > 1) res *= (x - 1);
    return res;
}

void solve() {
    map<int, int> r;
    scanf("%d %d", &n, &m);
    int res = 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i) continue;
        if (i >= m) res += getphi(n / i);
        if (i * i != n && n / i >= m) res += getphi(n / (n / i));
    }
    printf("%d\n", res + 1);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
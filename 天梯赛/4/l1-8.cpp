#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define int long long
const int mod = 998244353;
const int N = 1e5 + 5;

int a[N], xc, n, b[N], cnt;

void d(int x) {
    cnt = 0;
    if (x == 0) b[cnt = 1] = 0;
    while (x > 0) {
        b[++cnt] = x % 10;
        x /= 10;
    }
    reverse(b + 1, b + cnt + 1);
}

void solve() {
    cin >> a[1] >> a[2] >> n;
    int p = 1;
    xc = 2;
    while (xc < n) {
        int i;
        d(a[p] * a[p + 1]);
        for (i = xc + 1; i <= xc + cnt && i <= n; i++) {
            a[i] = b[i - xc];
        }
        xc = i - 1;
        p++;
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
}

signed main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
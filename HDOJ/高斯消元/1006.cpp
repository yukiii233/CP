// http://hzwer.com/5491.html
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define int long long
const int mod = 998244353;
const int N = 1e4 + 5;

int n;
ll a[N];
bool zero;

int bit(ll x, int k) {
    return (x >> (60 - k)) & 1;
}

void gauss() {
    int k = 1;
    for (int i = 0; i <= 60 && k <= n; i++) {
        if (bit(a[k], i) == 0) {
            for (int j = k + 1; j <= n; j++) if (bit(a[j], i)) {
                swap(a[k], a[j]);
                break;
            }
        }
        if (!bit(a[k], i)) continue;
        for (int j = 1; j <= n; j++) if (j != k && bit(a[j], i)) a[j] ^= a[k];
        k++;
    }
    zero = (k != n + 1);
    n = k - 1;
}
ll query(ll x) {
    x -= zero;
    if (x == 0) return 0;
    if (x >= (1ll << n)) return -1;
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        if ((1ll << (n - i)) & x) res ^= a[i];
    }
    return res;
}

void solve() {
    static int Case = 0;
    printf("Case #%lld:\n", ++Case);
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    gauss();
    int Q;
    scanf("%lld", &Q);
    while (Q--) {
        ll x;
        scanf("%lld", &x);
        printf("%lld\n", query(x));
    }
    return;
}

signed main() {
    int T;
    scanf("%lld", &T);
    while (T--) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

ll a[61][61] = {};
int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    int az = __builtin_ctz(a);
    int bz = __builtin_ctz(b);
    int z = min(az, bz);
    b >>= bz;
    while (a) {
        a >>= az;
        int diff = a - b;
        az = __builtin_ctz(diff);
        b = min(a, b), a = abs(diff);
    }
    return b << z;
}

void solve() {
    int n, m;
    cin >> n >> m;
    int pn = n / 250, pm = m / 250;
    ll res = a[pn][pm];
    pn *= 250, pm *= 250;
    for (int i = pn + 1; i <= n; i++) {
    	for (int j = pm + 1; j <= m; j++) res += gcd(i | j, j & i);
    }
    for (int i = 1; i <= pn; i++) {
    	for (int j = pm + 1; j <= m; j++) res += gcd(i | j, j & i);
    }
    for (int i = pn + 1; i <= n; i++) {
    	for (int j = 1; j <= pm; j++) res += gcd(i | j, j & i);
    }
	printf("%lld\n", res);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
} 

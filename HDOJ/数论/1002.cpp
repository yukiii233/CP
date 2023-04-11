#include <bits/stdc++.h>
using namespace std;

const int mod = 9973;
const int N = 1e5 + 5;

int fpow(int a, int b) {
    int res = 1;
    for (; b; b >>= 1, a = a * 1ll * a % mod) if (b & 1) res = res * 1ll * a % mod;
    return res;
}

void solve() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", a * 1ll * fpow(b, mod - 2) % mod);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
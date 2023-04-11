#include <bits/stdc++.h>
using namespace std;

const int mod = 9973;
const int N = 1e5 + 5;
char s[N];
int n, Q, h[N], inv[mod + 5];

int fpow(int a, int b) {
    int res = 1;
    for (; b; b >>= 1, a = a * 1ll * a % mod) if (b & 1) res = res * 1ll * a % mod;
    return res;
}

void solve() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    h[0] = 1;
    for (int i = 1; i <= n; i++) h[i] = h[i - 1] * 1ll * (s[i] - 28) % mod;  
    while (Q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%lld\n", h[r] * 1ll * inv[h[l - 1]] % mod);
    }
}

int main() {
    inv[0] = 1;
    for (int i = 1; i < mod; i++) inv[i] = fpow(i, mod - 2);
    while (~scanf("%d", &Q)) {
        solve();
    }
    return 0;
}
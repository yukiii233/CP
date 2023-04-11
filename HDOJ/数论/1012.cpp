#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1000000007, mod = 1000000006;
const int N = 1e5 + 5;
bool M;

int qpow(int a, int b, int mod) {
    if (b < 0) b += mod;
    int res = 1;
    for (; b; b >>= 1, a = a * 1ll * a % mod) if (b & 1) res = res * 1ll * a % mod;
    return res;
}
char t[15] = "1000000006";
char s[100005];
bool cmp() {
    if (strlen(s) != 10) return strlen(s) > 10;
    for (int i = 0; i < 10; i++) if (s[i] != t[i]) {
        return s[i] > t[i];
    }
    return 0;
}
int CALC() {
    int res = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++) res = (res * 1ll * 10 % mod + (s[i] - '0')) % mod;
    return res;
}

void solve() {
    int res = 0;
    if (!cmp()) {
        printf("%d\n", CALC());
        printf("%d\n", qpow(2, CALC() - 1, MOD));
    } else {
        printf("%d\n", qpow(2, (CALC() + mod - 1) % mod + mod, MOD));
    }
}

int main() {
    while (~scanf("%s", s)) {
        solve();
        M = 0;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 6e5 + 5;

char s[N];
int l, r, Q, sum[N];

int fpow(int a, int b) {
    int res = 1;
    for (; b; b >>= 1, a = a * 1ll * a % mod) if (b & 1) res = res * 1ll * a % mod;
    return res;
}

void solve() {
    scanf("%d", &Q);
    s[l = r = 1] = '1';
    sum[r] = 1;
    while (Q--) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            char x[6];
            scanf("%s", x);
            s[++r] = x[0];
            sum[r] = (sum[r - 1] * 10ll % mod) + x[0] - '0';
            sum[r] %= mod;
        } else if (op == 2) l++;
        else {
            int res = 0;
            res = (sum[r] + mod - sum[l - 1] * 1ll * fpow(10, r - l + 1) % mod) % mod;
            printf("%d\n", res);
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
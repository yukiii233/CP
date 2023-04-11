#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;
int n, m;
bool M;

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
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int mul(int a, int b, int mod) {
    if ((a * 1ll * b) >= mod) M = 1;
    return (a * 1ll * b) % mod;
}
int fpow(int a, int b, int mod) {
    M = 0;
    int res = 1;
    for (; b; b >>= 1, a = mul(a, a, mod)) if (b & 1) res = mul(res, a, mod);
    return res;
}

int CALC(int n, int mod) {
    if (n == 0)
        return 1;
    int phi = getphi(mod);
    int a = n % 10;
    if (gcd(a, mod) == 1) {
        return fpow(a, CALC(n / 10, phi), mod);
    } else {
        return fpow(a, CALC(n / 10, phi) + (M ? phi : 0), mod);    
    }
    return 233;
}

void solve() {
    int n, m;
    M = 0;
    scanf("%d %d", &n, &m);
    printf("%d\n", CALC(n, m));
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
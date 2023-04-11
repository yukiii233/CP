//https://blog.csdn.net/wust_zzwh/article/details/51966450
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;
const int N = 1e7 + 5;

int P[N], pcnt, R[N];
int phi[N], sum[N];
bool vis[N];

void add(int &x, int y) {
    ((x += y) >= mod) && (x -= mod);
}
void init(int n) {
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            P[++pcnt] = i;
            R[i] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= pcnt && i * P[j] <= n; j++) {
            vis[i * P[j]] = 1;
            R[i * P[j]] = P[j];
            if (i % P[j] != 0) {
                phi[i * P[j]] = phi[i] * phi[P[j]];
            } else {
                phi[i * P[j]] = phi[i] * P[j];
                break;
            }
        }
    }
    phi[1] = 1;
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1], add(sum[i], phi[i]);
}
int F(int n, int m) {
    if (n == 1) return sum[m];
    if (m <= 1) return m * phi[n];
    return (phi[R[n]] * 1ll * F(n / R[n], m) % mod + F(n, m / R[n])) % mod;
}

int K, n, m, p, M;

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

int CALC(int mod) {
    if (mod == 1) return 0;
    if (gcd(K, mod) == 1) {
        return fpow(K, CALC(phi[mod]), mod);
    } else {
        return fpow(K, CALC(phi[mod]) + (1 ? phi[mod] : 0), mod);    
    }
    return 233;
}

void solve() {
    K = F(n, m);
    printf("%d\n", CALC(p));
}

int main() {
    init(1e7);
    while (scanf("%d %d %d", &n, &m, &p) == 3) {
        solve();
    }
    return 0;
}
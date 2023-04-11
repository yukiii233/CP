#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 15001;
ll a[N][N];

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

void init() {
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            a[i][j] = gcd(i & j, i | j);
        }
    }
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1]; 
        }
    }
}

int main() {
   // freopen("qwq.out", "w", stdout);
    init();
    /*for (int i = 0; i < N; i += 250) {
        for (int j = 0; j < N; j += 250) printf("%lld, ", a[i][j]);
    }*/
    int n, m;
    cin >> n >> m;
    cout << a[n][m] << '\n';
    return 0;
}
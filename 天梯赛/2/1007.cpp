#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

int m, n;
char s[36];

void solve() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%s", s + 1);
        ll x = 0, sum = (1 << (n - 1));
        for (int i = 1; i <= n; i++) {
            if (s[i] != 'y') x += sum;
            sum >>= 1;
        }
        printf("%d\n", x + 1);
    }
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
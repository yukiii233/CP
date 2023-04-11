#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 11;
int a, b, dig[N], cnt;
int f[N][N][2][2];

int dfs(int p, int last, int have0, int limit) {
    if (p == 0) return 1;
    int &res = f[p][last][have0][limit];
    if (res != -1) return res;
    res = 0;
    int mx = limit ? dig[p] : 9;
    int rx = mx;
    if (!have0) mx = min(mx, last);
    for (int i = 0; i <= mx; i++) {
        if (!have0 && i == 0) continue;
        if (!have0 && last % i != 0) continue;
        res += dfs(p - 1, i, have0 && i == 0, limit && i == rx);
    }
    return res;
}
int calc(int x) {
    cnt = 0;
    while (x) {
        dig[++cnt] = x % 10;
        x /= 10;
    }
    memset(f, -1, sizeof f);
    return dfs(cnt, 0, 1, 1);
}

void solve() {
    scanf("%d %d", &a, &b);
    printf("%d\n", calc(b) - calc(a - 1));
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
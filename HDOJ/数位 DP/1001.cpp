#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 25;
ll f[N][3][2];
int cnt, dig[N];

ll dfs(int p, int cur, int limit) {
    if (p == 0) return cur == 2;
    ll &res = f[p][cur][limit];
    if (res != -1) return res;
    res = 0;
    int mx = limit ? dig[p] : 9;
    for (int i = 0; i <= mx; i++) {
        int nxt = cur;
        if (cur == 0 && i == 4) nxt = 1;
        else if (cur == 1 && i == 9) nxt = 2;
        else if (cur == 1 && i != 9 && i != 4) nxt = 0;
        res += dfs(p - 1, nxt, limit && i == mx);
    }
    return res;
}

ll div(ll n) {
    cnt = 0;
    while (n) {
        dig[++cnt] = n % 10;
        n /= 10;
    }
    return dfs(cnt, 0, 1);
}

void solve() {
    ll n;
    memset(f, -1, sizeof f);
    scanf("%lld", &n);
    printf("%lld\n", div(n));
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
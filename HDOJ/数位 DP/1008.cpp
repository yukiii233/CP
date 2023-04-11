#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 20;
int cnt, dig[N], k;

ll f[N][11][1026][2];

int upd(int x, int S) {
    int T = S;
    for (int i = x; i <= 9; i++) if ((S & (1 << i)) != 0) {
        T ^= (1 << i);
        break;
    }
    T ^= (1 << x);
    return T;
}

ll dfs(int p, int S, int have0, int limit) {
    if (p == 0) return __builtin_popcountll(S) == k;
    ll &re = f[p][k][S][have0];
    if (!limit && re != -1) return re;
    ll res = 0;
    int mx = limit ? dig[p] : 9;
    for (int i = 0; i <= mx; i++) {
        int nxt;
        if (have0 && i == 0) nxt = 0;
        else nxt = upd(i, S);
        res += dfs(p - 1, nxt, have0 && i == 0, limit && i == mx);
    }
    if (!limit) re = res;
    return res;
}

ll calc(ll x) {
    cnt = 0;
    while (x) {
        dig[++cnt] = x % 10;
        x /= 10;
    }
    return dfs(cnt, 0, 1, 1);
}

void solve() {
    static int Case = 0;
    ++Case;
    ll a, b;
    scanf("%lld %lld %d", &a, &b, &k);
    printf("Case #%d: %lld\n", Case, calc(b) - calc(a - 1));
}

int main() {
    memset(f, -1, sizeof f);
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
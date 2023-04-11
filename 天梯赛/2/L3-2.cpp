#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 5e5 + 5;

char sss[5];
int n, Q, bl[N];

int tot, fa[N], tr[N][2];

int getdir(int x) {
    return tr[fa[x]][1] == x;
}
void rotate(int x) {
    int y = fa[x], z = fa[y], d = getdir(x);
    tr[y][d] = tr[x][d ^ 1];
    if (tr[x][d ^ 1]) fa[tr[x][d ^ 1]] = y;
    fa[y] = x;
    tr[x][d ^ 1] = y;
    fa[x] = z;
    if (z) tr[z][y == tr[z][1]] = x;
}
void splay(int x) {
    for (int f = fa[x]; f = fa[x], f; rotate(x)) {
        if (fa[f]) rotate(getdir(f) == getdir(x) ? f : x);
    }
}
int pre(int u) {
    splay(u);
    while (tr[u][0]) u = tr[u][0];
    splay(u);
    return u;
}
int suf(int u) {
    splay(u);
    while (tr[u][1]) u = tr[u][1];
    splay(u);
    return u;
}

struct data {
    int x1, y1, x2, y2;
} q[N];

void solve() {
    scanf("%d %d", &n, &Q);
    vector<int> yy[n + 1];
    for (int i = 1; i <= Q; i++) {
        scanf("%s %d %d %d", sss, &q[i].x1, &q[i].x2, &q[i].y1);
        yy[q[i].x1].push_back(q[i].y1);
        yy[q[i].x2].push_back(q[i].y1);
    }
    for (int i = 1; i <= n; i++) {
        yy[i].push_back(0);
        yy[i].push_back(1e9);
        sort(yy[i].begin(), yy[i].end());
        yy[i].resize(unique(yy[i].begin(), yy[i].end()) - yy[i].begin());
    }
    for (int i = 1; i <= Q; i++) {
        q[i].y2 = lower_bound(yy[q[i].x2].begin(), yy[q[i].x2].end(), q[i].y1) - yy[q[i].x2].begin();
        q[i].y1 = lower_bound(yy[q[i].x1].begin(), yy[q[i].x1].end(), q[i].y1) - yy[q[i].x1].begin();
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (int)(yy[i].size()); j++) yy[i][j] = ++tot, bl[tot] = i;
        for (int j = 0; j < (int)(yy[i].size()) - 1; j++) tr[yy[i][j]][1] = yy[i][j + 1], fa[yy[i][j + 1]] = yy[i][j];
    }
    ll ans = n * 1ll * (n + 1) * (2 * n + 1) / 6;
    for (int i = 1; i <= Q; i++) {
        auto [x1, y1, x2, y2] = q[i];
        int u = yy[x1][y1], v = yy[x2][y2];
        ll l1 = bl[pre(u)], r1 = bl[suf(u)], l2 = bl[pre(v)], r2 = bl[suf(v)];
        ans -= l1 * r1 + l2 * r2;
        ans += l1 * r2 + l2 * r1;
        splay(u), splay(v);
        int c1 = tr[u][1], c2 = tr[v][1];
        tr[u][1] = c2, fa[c2] = u;
        tr[v][1] = c1, fa[c1] = v;
        printf("%lld\n", ans);
    }
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
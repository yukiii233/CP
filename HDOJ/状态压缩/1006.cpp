#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
void add(int &x, int y) {
    ((x += y) >= mod) && (x -= mod);
}

int n, m, C, D;
int dp[105][1026][25];
char a[105][15];

void dfs(int i, int p, int now, int use, int pre, int pu) {
    if (pu + use > D) return;
    if (p == m) {
        add(dp[i][now][pu + use], dp[i - 1][pre][pu]);
        return;
    }
    if (a[i][p] == '0') {
        if ((pre >> p) & 1) dfs(i, p + 1, now | (1 << p), use, pre, pu);
        else return;
    } else {
        if ((pre >> p) & 1) {
            dfs(i, p + 1, now | (1 << p), use + 1, pre, pu);
            dfs(i, p + 1, now, use, pre, pu);
            if (p != 0 && !((now >> (p - 1)) & 1)) dfs(i, p + 1, now | (3 << (p - 1)), use, pre, pu);
        } else {
            dfs(i, p + 1, now | (1 << p), use, pre, pu);
        }
    }
}

void solve() {
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; i++) {
        scanf("%s", a[i]);
    }
    int mask = (1 << m) - 1;
    dp[0][mask][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int s = 0; s <= mask; s++) {
            for (int k = 0; k <= D; k++) if (dp[i - 1][s][k]) {
                dfs(i, 0, 0, 0, s, k);
            }
        }
    }
    int res = 0;
    for (int i = C; i <= D; i++) add(res, dp[n][mask][i]);
    printf("%d\n", res);
}

int main() {
    while (~scanf("%d %d %d %d", &n, &m, &C, &D)) {
        solve();
    }
    return 0;
}
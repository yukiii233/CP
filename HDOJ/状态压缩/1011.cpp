#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[101][11];
int sta[101][175], cnt[101];
int f[101][170][170];

bool check(int sta) {
    for (int i = 1; i <= m - 2; i++) {
        if (((sta >> i) & 1) && ((sta >> (i + 2)) & 1)) return 0;
    }
    return 1;
}
void dfs(int p, int cur, const int r) {
    if (p == m + 1) {
        if (check(cur)) sta[r][++cnt[r]] = cur;
        assert(cnt[r] < 170);
        return;
    }
    if (a[r][p] == 1) dfs(p + 1, cur | (1 << p), r);
    dfs(p + 1, cur, r);
}

void solve() {
    memset(f, -1, sizeof f);
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; i++)   
        for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++) dfs(1, 0, i);
    if (n == 1) {
        int res = 0;
        for (int i = 1; i <= cnt[n]; i++) {
            res = max(res, __builtin_popcount(sta[1][i]));
        }
        printf("%d\n", res);
        return;
    }
    for (int i = 1; i <= cnt[2]; i++) {
        for (int j = 1; j <= cnt[1]; j++) {
            int ci = sta[2][i], cj = sta[1][j];
            bool flag = 1;
            for (int k = 1; k <= m; k++) if ((ci >> k) & 1) {
                if (k < m && ((cj >> (k + 1)) & 1)) flag = 0;
                if (k > 1 && ((cj >> (k - 1)) & 1)) flag = 0;
            }
            if (!flag) continue;
            f[2][i][j] = __builtin_popcount(ci) + __builtin_popcount(cj);
        }
    }
    for (int k = 3; k <= n; k++) {
        for (int i = 1; i <= cnt[k]; i++) {
            for (int j = 1; j <= cnt[k - 1]; j++) {
                for (int p = 1; p <= cnt[k - 2]; p++) if (f[k - 1][j][p] != -1) {
                    bool flag = 1;
                    int ci = sta[k][i], cj = sta[k - 1][j];
                    for (int k = 1; k <= m; k++) if ((ci >> k) & 1) {
                        if (k < m && ((cj >> (k + 1)) & 1)) flag = 0;
                        if (k > 1 && ((cj >> (k - 1)) & 1)) flag = 0;
                    }
                    ci = sta[k][i], cj = sta[k - 2][p];
                    for (int k = 1; k <= m; k++) if ((ci >> k) & 1) {
                        if ((cj >> k) & 1) flag = 0;
                    }
                    if (!flag) continue;
                    f[k][i][j] = max(f[k][i][j], f[k - 1][j][p] + __builtin_popcount(ci));
                }
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= cnt[n]; i++) {
        for (int j = 1; j <= cnt[n - 1]; j++) res = max(res, f[n][i][j]);
    }
    printf("%d\n", res);
}

int main() {
    while (scanf("%d %d", &n, &m) == 2) {
        solve();
    }
    return 0;
}
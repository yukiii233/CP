#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define free miku
const int mod = 998244353;
const int N = 100 + 5;

int n, D, R;
int a[N][N], ans, val[N];
bool free[N];
vector<int> v;

void dfs(int p) {
    if (p == n - R) {
        int res = 0;
        for (int i = R; i; i--) {
            int cur = a[i][n + 1], pos = 0;
            for (int j = 1; j <= n; j++) if (a[i][j] == 1) {
                 if (free[j]) cur ^= val[j];
                 else {
                     if (!pos) pos = j;
                     else cur ^= val[j];
                 }
            }
            val[pos] = cur;
            assert(pos);
        }
        for (int i = 1; i <= n; i++) res += val[i];
        ans = min(ans, res);
        return;
    }
    val[v[p]] = 0;
    dfs(p + 1);
    val[v[p]] = 1;
    dfs(p + 1);
}

void gauss() {
    int k = 1;
    for (int i = 1; i <= n; i++) {
        if (k > n) break;
        if (a[k][i] == 0) {
            for (int j = k + 1; j <= n; j++) if (a[j][i] != 0) {
                for (int l = 1; l <= n + 1; l++) swap(a[j][l], a[k][l]);
                break;
            }
        }
        if (a[k][i] == 0) {
            free[i] = 1;
            v.push_back(i);
            continue;
        }
        for (int j = k + 1; j <= n; j++) if (a[j][i] == 1) {
            for (int l = i; l <= n + 1; l++) a[j][l] ^= a[k][l];
        }
        k++;
    }
    R = k - 1;
    if ((int)v.size() != n - R) while (1);
    for (int i = k; i <= n; i++) if (a[i][n + 1] == 1) return;
    dfs(0);
}


void solve() {
    memset(a, 0, sizeof a);
    memset(free, 0, sizeof free);
    memset(val, 0, sizeof val);
    v.clear();
    scanf("%d %d", &n, &D);
    for (int i = 1; i <= n; i++) {
        for (int j = max(i - D, 1); j <= n && j <= i + D; j++) a[i][j] = 1;
        scanf("%d", &a[i][n + 1]);
    }
    ans = 360;
    gauss();
    if (ans == 360) printf("impossible\n");
    else printf("%d\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
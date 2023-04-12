#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;
const int N = 12;

int n, dp[N][500000];
bool a[N][N];
char s[15];
int ans[N], m, state[N][1 << N], cnt[N];

int fpow(int a, int b) {
    int res = 1;
    for (; b; b >>= 1, a = a * 1ll * a % mod) if (b & 1) res = res * 1ll * a % mod;
    return res;
}

int trans(int cur, int sta) {
    static int f[N], g[N];
    for (int i = n - m + 1; i >= 1; i--) f[i] = cur % (m + 1), cur /= m + 1;
    for (int i = 1; i <= n - m + 1; i++) {
        bool flag = 1;
        for (int j = i; j <= i + m - 1; j++) {
            int now = (sta >> (j - 1)) & 1;
            if (now == 0) flag = 0; 
        }
        if (flag) g[i] = f[i] + 1;
        else g[i] = 0;
        if (g[i] == m) return -1;
    }
    int res = 0;
    for (int i = 1; i <= n - m + 1; i++) res = res * (m + 1) + g[i];
    return res;
}
void add(int &x, int y) {
    ((x += y) >= mod) && (x -= mod);
}

int calc() {
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    int mask = 0;
    for (int i = 1; i <= n - m + 1; i++) mask = mask * (m + 1) + m;
    for (int i = 0; i < n; i++) {
        for (int cur = 0; cur <= mask; cur++) if (dp[i][cur]) {
            for (int k = 1; k <= cnt[i + 1]; k++) {
                int nxt = state[i + 1][k];
                int tr = trans(cur, nxt);
                if (tr == -1) continue;
                add(dp[i + 1][tr], dp[i][cur]);
            }
        }
    }
    int res = 0;
    for (int cur = 0; cur <= mask; cur++) add(res, dp[n][cur]);
    return res;
}
void dfs(int i, int p, int res) {
    if (p == n + 1) {
        state[i][++cnt[i]] = res;
        return;
    }
    if (a[i][p] == 1) {
        dfs(i, p + 1, res | (1 << (p - 1)));
        dfs(i, p + 1, res);
    } else dfs(i, p + 1, res);
}

void solve() {
    int count = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        for (int j = 1; j <= n; j++) a[i][j] = s[j] == 'o', count += a[i][j];
    }
    for (int i = 1; i <= n; i++) cnt[i] = 0, dfs(i, 1, 0);
    ans[1] = 1, ans[n + 1] = fpow(2, count);
    for (int i = 2; i <= n; i++) m = i, ans[i] = calc();
    for (int i = 0; i <= n; i++) printf("%d\n", (ans[i + 1] + mod - ans[i]) % mod);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
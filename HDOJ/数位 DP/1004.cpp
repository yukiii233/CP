#include <bits/stdc++.h>
using namespace std;

const int mod = 1e8;
const int N = 100 + 5;

int n, m;
char s[N], num[N];
int f[N][N][10][2][2];

int dfs(int p, int cur, int last, int limit, int have0) {
    if (p == 0) return cur == m;
    int &re = f[p][cur][last][limit][have0];
    if (re != -1) return re;
    re = 0;
    int mx = limit ? num[p] - '0' : 9;
    for (int i = 0; i <= mx; i++) {
        int nxt;
        if (!have0) {
            if (cur == 0) {
                bool p2 = (s[cur + 1] == '/' && i > last) || (s[cur + 1] == '\' && i < last) || (s[cur + 1] == '-' && i == last);
                if (!p2) continue;
                nxt = 1;
            } else if (cur != m) {
                bool p1 = (s[cur] == '/' && i > last) || (s[cur] == '\' && i < last) || (s[cur] == '-' && i == last);
                bool p2 = (s[cur + 1] == '/' && i > last) || (s[cur + 1] == '\' && i < last) || (s[cur + 1] == '-' && i == last);
                if (!p1 && !p2) continue;
                nxt = cur + p2;
            } else {
                bool p1 = (s[cur] == '/' && i > last) || (s[cur] == '\' && i < last) || (s[cur] == '-' && i == last);
                if (!p1) continue;
                nxt = cur;
            }
        } else nxt = 0;
        re = (re + dfs(p - 1, nxt, i, limit && i == mx, have0 && i == 0)) % mod;
    }
    return re;
}

int solve() {
    n = strlen(num + 1);
    m = strlen(s + 1);
    reverse(num + 1, num + n + 1);
    memset(f, -1, sizeof f);
    return dfs(n, 0, 0, 1, 1);
}

int main() {
    while (scanf("%s", s + 1) != EOF) {
        int re1, re2;
        scanf("%s", num + 1);
        re1 = solve();
        scanf("%s", num + 1);
        re2 = solve();
        printf("%08d\n", (re2 + mod - re1) % mod);
    }
    return 0;
}

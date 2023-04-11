#include <bits/stdc++.h>
using namespace std;

#define data matoka
const int N = 10 + 7;

int n, a[N][N];
string data;
int cnt, vcnt;
int sta[1989], val[N][1989];
int f[2][1989];
pair<int, int> v[1989 * 1975];

bool check(int sta) {
    for (int i = 1; i < n; i++) {
        if (((sta >> i) & 1) && ((sta >> (i + 1)) & 1)) return 0;
    }
    return 1;
}
void dfs(int p, int cur) {
    if (p == n + 1) {
        if (check(cur)) sta[++cnt] = cur;
        return;
    }
    dfs(p + 1, cur), dfs(p + 1, cur | (1 << p));
}
bool check(int a, int b) {
    for (int i = 1; i <= n; i++) {
        if (((a >> i) & 1) && ((b >> i) & 1)) return 0;
    }
    for (int i = 1; i < n; i++) {
        if (((a >> i) & 1) && ((b >> (i + 1)) & 1)) return 0;
    }
    for (int i = 1; i < n; i++) {
        if (((b >> i) & 1) && ((a >> (i + 1)) & 1)) return 0;
    }
    return 1;
}

bool input(int x) {
    if (!getline(cin, data)) return 0;
    stringstream ss(data);
    if (data == "") return 0;
    static string s;
    int p = 0;
    while (ss >> s) {
        a[x][++p] = stoi(s);
    }
    return 1;
}
bool solve() {
    n = 0;
    while (input(++n));
    n--;
    if (n == 0) return 0;
    cnt = 0;
    dfs(1, 0);
    vcnt = 0;
    for (int i = 1; i <= cnt; i++)
        for (int j = 1; j <= cnt; j++) if (check(sta[i], sta[j])) {
            v[++vcnt] = {i, j};
        }  
    int cur = 0;
    memset(f[cur], 0, sizeof f[cur]);
    if (n == 1) return printf("%d\n", a[1][1]), 1;
    for (int k = 1; k <= cnt; k++) {
        for (int i = 1; i <= n; i++) {
            val[i][k] = 0;
            for (int j = 1; j <= n; j++) if ((sta[k] >> j) & 1) val[i][k] += a[i][j];
        }
    }
    for (int r = 1; r <= vcnt; r++) {
        int i = v[r].first, j = v[r].second;
        f[cur][i] = max(f[cur][i], val[2][i] + val[1][j]);
    }
    for (int k = 3; k <= n; k++) {
        cur ^= 1;
        memset(f[cur], 0, sizeof f[cur]);
        for (int r = 1; r <= vcnt; r++) {
            int i = v[r].first, j = v[r].second;
            if (f[cur ^ 1][j] == 0) continue;
            f[cur][i] = max(f[cur][i], val[k][i] + f[cur ^ 1][j]);
        }
    }
    printf("%d\n", *max_element(f[cur] + 1, f[cur] + cnt + 1));
    return 1;
}

int main() {
    while (solve());
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 500 + 5;

int n;
int f[N][N], dis[N];
vector<int> v[2];
char s[6];

void solve() {
    memset(f, 0x3f, sizeof f);
    memset(dis, 0, sizeof dis);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int num;
        scanf("%s %d", s + 1, &num);
        if (s[1] == 'F') {
            v[0].push_back(i);
            for (int j = 1; j <= num; j++) {
                int id, d;
                scanf("%d:%d", &id, &d);
                f[i][id] = d;
            }
        } else {
            v[1].push_back(i);
            for (int j = 1; j <= num; j++) {
                int id, d;
                scanf("%d:%d", &id, &d);
                f[i][id] = d;
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
        }
    }
    int re1 = 0x3f3f3f3f, re2 = 0x3f3f3f3f;
    for (int x : v[0]) {
        for (int y : v[1]) {
            dis[x] = max(dis[x], f[y][x]);
        }
        re1 = min(dis[x], re1);
    }
    for (int x : v[1]) {
        for (int y : v[0]) {
            dis[x] = max(dis[x], f[y][x]);
        }
        re2 = min(dis[x], re2);
    }
    bool fg = 0;
    for (int x : v[0]) if (dis[x] == re1) {
        if (fg) printf(" ");
        else fg = 1;
        printf("%d", x);
    }
    puts("");
    fg = 0;
    for (int x : v[1]) if (dis[x] == re2) {
        if (fg) printf(" ");
        else fg = 1;
        printf("%d", x);
    }
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
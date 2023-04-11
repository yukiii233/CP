#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 257;

int n, m, num;
char s[N + 2][N + 2];
bitset<N * N> a[N * N];
bool broken[N][N];

int id(int x, int y) {
    return (x - 1) * m + y;
}

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool check(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

bool gauss() {
    int k = 1;
    for (int i = 1; i <= m * n; i++) {
        if (k > n * m) break;
        if (a[k][i] == 0) {
            for (int j = k + 1; j <= n * m; j++) if (a[j][i] != 0) {
                swap(a[j], a[k]);
                break;
            }
        }
        if (a[k][i] == 0) 
            continue;
        for (int j = k + 1; j <= n * m; j++) if (a[j][i] == 1) {
            a[j] ^= a[k];
        }
        k++;
    }
    for (int i = k; i <= n * m; i++) if (a[i][m * n + 1] == 1) return 0;
    return 1;
}

void solve() {
    static int Case = 0;
    printf("Case #%d:\n", ++Case);
    memset(broken, 0, sizeof broken);
    scanf("%d %d %d", &n, &m, &num);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
    }
    for (int i = 1; i <= num; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        broken[x][y] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[id(i, j)].reset();
            if (!broken[i][j]) a[id(i, j)].set(id(i, j));
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (!check(x, y) || broken[x][y]) continue;
                a[id(i, j)].set(id(x, y));
            }
            if (s[i][j] == 'B') a[id(i, j)].set(n * m + 1);
        }
    }
    gauss() ? puts("YES") : puts("NO");
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
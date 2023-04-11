#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 30 + 5;

int n, m, g[N][N], a[N * N][N * N], val[N * N];

int id(int x, int y) {
    return (x - 1) * m + y;
}

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void gauss() {
    int k = 1;
    for (int i = 1; i <= n * m; i++) {
        if (k > n * m) break;
        if (a[k][i] == 0) {
            for (int j = k + 1; j <= n * m; j++) if (a[j][i]) {
                for (int l = 1; l <= n * m + 1; l++) swap(a[k][l], a[j][l]);
                break;
            }
        }
        if (a[k][i] == 0) {
            val[i] = 0;
            continue;
        }
        for (int j = k + 1; j <= n * m; j++) if (a[j][i]) {
            int t = a[k][i] == 1 ? (3 - a[j][i]) : (a[j][i] == 1 ? 1 : 2);
            for (int l = 1; l <= n * m + 1; l++) {
                a[j][l] = (a[k][l] * t + a[j][l]) % 3;
            }
        }
        k++;
    }
    for (int i = n * m; i >= 1; i--) {
        int tmp = 0, pos = 0;
        for (int j = 1; j <= n * m; j++) if (a[i][j]) {
            if (val[j] == -1) pos = j;
            else tmp = (tmp + val[j] * a[i][j]) % 3;
        }
        for (int j = 0; j < 3; j++) if ((tmp + a[i][pos] * j) % 3 == a[i][n * m + 1]) {
            val[pos] = j;
            break;
        }
    }
}

void solve() {
    memset(val, -1, sizeof val);
    memset(a, 0, sizeof a);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) scanf("%d", &g[i][j]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (x < 1 || y < 1 || x > n || y > m) continue;
                a[id(i, j)][id(x, y)] = 1;
            }
            a[id(i, j)][n * m + 1] = (3 - g[i][j]) % 3;
            a[id(i, j)][id(i, j)] = 2;
        }
    }
    gauss();
    int res = 0;
    for (int i = 1; i <= n * m; i++) res += val[i];
    printf("%d\n", res);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= val[id(i, j)]; k++) {
                printf("%d %d\n", i, j);
                g[i][j] += 2;
                for (int kk = 0; kk < 4; kk++) {
                    int x = i + dx[kk], y = j + dy[kk];
                    if (x < 1 || y < 1 || x > n || y > m) continue;
                    g[x][y] += 1;
                }
            }
        }
    }
    return;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
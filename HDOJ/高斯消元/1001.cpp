#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 100 + 5;

int n, m;
char s[N], t[N];
int a[N][N], b[N][N];

bool gauss() {
    memcpy(b, a, sizeof b);
    int k = 1;
    for (int i = 1; i <= m; i++) {
        if (k > n) break;
        if (a[k][i] == 0) {
            for (int j = k + 1; j <= n; j++) if (a[j][i] != 0) {
                for (int l = 1; l <= m + 1; l++) swap(a[j][l], a[k][l]);
                break;
            }
        }
        if (a[k][i] == 0) continue;
        for (int j = k + 1; j <= n; j++) if (a[j][i] == 1) {
            for (int l = i; l <= m + 1; l++) a[j][l] ^= a[k][l];
        }
        k++;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m + 1; j++) printf("%d%c", a[i][j], " \n"[j == m + 1]);
    }
    int flag = 1;
    for (int i = k; i <= n; i++) if (a[i][m + 1] == 1) flag = 0;
    memcpy(a, b, sizeof a);
    return flag;
}

void solve() {
    for (int i = 1; i <= m; i++) {
        scanf("%s", s + 1);
        for (int j = 1; j <= n; j++) a[j][i] = s[j] - '0';
    }
    int num;
    scanf("%d", &num);
    while (num--) {
        scanf("%s %s", s + 1, t + 1);
        for (int i = 1; i <= n; i++) a[i][m + 1] = (s[i] - '0') ^ (t[i] - '0');
        gauss() ? printf("Yes\n") : printf("No\n");
    }
}

int main() {
    while (~scanf("%d %d", &n, &m)) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

int val[33] = {0, 0, 0, 0, 0, 0, 10000, 36, 720, 360, 80, 252, 108, 72, 54, 180, 72, 180, 119, 36, 306, 1080, 144, 1800, 3600};;
int n = 3, a[4][4], sumr[5], sumc[5], hc, hr;

void solve() {
    int sum = 0;
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++) {
            scanf("%d", &a[i][j]);
            sum += a[i][j];
        }
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++) {
            if (a[i][j] == 0) a[i][j] = 45 - sum;
        }
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++) sumr[i] += a[i][j], sumc[j] += a[i][j];
    for (int i = 1; i <= 3; i++) hc += a[i][i];
    hr += a[1][3] + a[2][2] + a[3][1];
    for (int k = 1; k <= 3; k++) {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d\n", a[x][y]);
    }
    int p;
    scanf("%d", &p);
    if (p <= 3) printf("%d\n", val[sumr[p]]);
    else if (p <= 6) printf("%d\n", val[sumc[p - 3]]);
    else if (p == 7) printf("%d\n", val[hc]);
    else printf("%d\n", val[hr]);
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
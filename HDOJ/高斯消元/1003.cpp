#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 50 + 5;

int n, m;
int a[N][N], b[N][N];

ll gauss() {
    int k = 1, re = 0;
    for (int i = 1; i <= m; i++) {
        if (k > n) break;
        if (a[k][i] == 0) {
            for (int j = k + 1; j <= n; j++) if (a[j][i] != 0) {
                for (int l = 1; l <= m + 1; l++) swap(a[j][l], a[k][l]);
                break;
            }
        }
        if (a[k][i] == 0) {
            re++;
            continue;
        }
        for (int j = k + 1; j <= n; j++) if (a[j][i] == 1) {
            for (int l = i; l <= m + 1; l++) a[j][l] ^= a[k][l];
        }
        k++;
    }
    for (int i = k; i <= n; i++) if (a[i][m + 1] == 1) return 0;
    if (m - k + 1 != re) while(1);
    return 1ll << (m - k + 1);
}

void solve() {
    static int Case = 0;
    printf("Case %d:\n", ++Case);
    memset(a, 0, sizeof a);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int num, x;
        cin >> num;
        for (int j = 1; j <= num; j++) {
            scanf("%d", &x);
            a[x][i] = 1;
        }
    }
    memcpy(b, a, sizeof b);
    int Q;
    cin >> Q;
    while (Q--) {
        memcpy(a, b, sizeof a);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i][m + 1]);
        }
        cout << gauss() << '\n';
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
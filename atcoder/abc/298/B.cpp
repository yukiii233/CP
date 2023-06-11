#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 100 + 5;

int n;
bool a[N][N], b[N][N], c[N][N];

void r() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) c[i][j] = a[n + 1 - j][i];
     for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) a[i][j] = c[i][j];
}
bool pd() {
     for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) if (a[i][j] == 1) {
            if (b[i][j] != 1) return 0;
        }
    }
    return 1;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cin >> b[i][j];
    }
    int k = 6;
    while (k--) {
        r();
        if (pd()) return cout << "Yes\n", void(); 
    }
    cout << "No\n";
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
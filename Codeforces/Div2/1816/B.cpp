#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const int mod = 998244353;
const int N = 1e5 + 5;
 
int n;
int a[2][N], b[2][N];
 
void solve() {
    cin >> n;
    int t = n * 2;
    for (int i = 0; i < n / 2; i++) {
        a[0][1 + i] = t--;
        a[0][n - i] = t--;
    }
    t = n;
    for (int i = 0; i < n / 2; i++) {
        a[1][1 + i] = t--;
        a[1][n - i] = t--;
    }
    for (int i = 1; i <= n; i++) {
        b[0][i] = a[0][i], b[1][i] = a[1][i];
        if (!(i & 1)) swap(b[1][i], b[0][i]);
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= n; j++) cout << b[i][j] << ' ';
        cout << '\n';
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
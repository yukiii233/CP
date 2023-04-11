#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

int a[25];

void solve() {
    for (int i = 0; i < 24; i++) cin >> a[i];
    int x;
    while (cin >> x) {
        if (x < 0 || x > 23) continue;
        int y = a[x];
        cout << y << ' ';
        if (y > 50) cout << "Yes\n";
        else cout << "No\n";
    }
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
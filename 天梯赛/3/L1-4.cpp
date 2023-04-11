#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

void solve() {
    int x, y;
    cin >> x >> y;
    int s = 100 * 100 / 2 - (100 * y + 5000 - 50 * (x + y));
    cout << s << '\n';
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
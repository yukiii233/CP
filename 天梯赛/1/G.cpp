#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;

ll n, m, q;

void solve() {
    cin >> n >> m >> q;
    set<int> s[2];
    while (q--) {
        int x, y;
        cin >> x >> y;
        s[x].insert(y);
    }
    cout << n * m - 1ll * s[0].size() * m - 1ll * s[1].size() * n + + 1ll * s[0].size() * s[1].size();
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
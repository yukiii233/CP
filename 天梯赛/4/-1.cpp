#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    cout << max(0ll, n - m * k) << '\n';
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
 #include <bits/stdc++.h>
using namespace std;
using ll = long long;

int Case;

int fpow(int a, ll b, int mod) {
    int res = 1;
    for (; b; b >>= 1, a = a * a % mod) if (b & 1) res = res * a % mod;
    return res;
}

void solve() {
    ll n;
    cin >> n;
    cout << "Case " << ++Case << ": " << (fpow(2, n - 1, 100) + fpow(2, n + n - 2, 100)) % 100 << '\n';
}

int main() {
    int T;
    while (cin >> T && T) {
        Case = 0;
        while (T--) solve();
        cout << '\n';
    }
    return 0;
}
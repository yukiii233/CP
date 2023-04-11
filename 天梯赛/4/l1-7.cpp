#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

int n, x;

void solve() {
    cin >> n;
    int mx = 0, mn = 1e9, xc = 0, nc = 0;
    while (n--) {
        cin >> x;
        if (x > mx) mx = x, xc = 1;
        else if (x == mx) xc++;
        if (x < mn) mn = x, nc = 1;
        else if (x == mn) nc++;
    }
    cout << mn << ' ' << nc << '\n';
    cout << mx << ' ' << xc << '\n';
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
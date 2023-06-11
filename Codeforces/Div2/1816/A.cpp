#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

void solve() {
     int a, b;
     cin >> a >> b;
     cout << 2 << '\n';
     cout << a + (a == 1000000000 ? -1 : 1) << ' ' << 1 << '\n';
     cout << a << ' ' << b << '\n';
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
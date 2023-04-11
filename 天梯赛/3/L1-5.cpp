#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

void solve() {
    double a, b;
    cin >> a >> b;
    double s = a / b / b;
    printf("%.1lf\n", s);
    if (s > 25.0) {
        cout << "PANG";
    } else cout << "Hai Xing";
    cout << '\n';
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
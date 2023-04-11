#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

void solve() {
    double a, b, c;
    bool p;
    scanf("%lf %d %lf", &a, &p, &c);
    b = !p ? 2.455 : 1.26;
    double r = a * b;
    printf("%.2lf ", r);
    a * b > c ? cout << "T_T" : cout << "^_^";
    cout << '\n';
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;

struct node {
    string s, t;
} a[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].s;
        cin >> a[i].t;
        cin >> a[i].t;
    }
    a[0] = {"00:00:00", "00:00:00"};
    a[++n] = {"23:59:59", "23:59:59"};
    sort(a, a + n + 1, [](node x, node y) {
       return x.s < y.s; 
    });
    for (int i = 1; i <= n; i++) {
        if (a[i].s != a[i - 1].t) cout << a[i - 1].t << " - " << a[i].s << '\n';
    }
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
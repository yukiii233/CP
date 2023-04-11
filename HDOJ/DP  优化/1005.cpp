#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 4e5 + 5;

int n, T;
ll dp[N], s[N], a[N];
int q[N], ql, qr;

ll y(int i) { return dp[i] - s[i] + i * a[i + 1]; }
ll x(int i) { return a[i + 1]; }

void solve() {
    for (int i = 1; i <= n; i++) cin >> a[i], dp[i] = 0;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    q[ql = qr = 1] = 0;
    for (int i = T; i <= n; i++) {
        while (ql < qr && (y(q[ql + 1]) - y(q[ql]) <= (x(q[ql + 1]) - x(q[ql])) * i)) ql++;
        //cout << i << ' ' << q[ql] << '\n';
        dp[i] = y(q[ql]) - i * x(q[ql]) + s[i];
        if (i - T + 1 < T) continue;
        while (ql < qr && (y(i - T + 1) - y(q[qr])) * (x(q[qr]) - x(q[qr - 1])) <= 
            (x(i - T + 1) - x(q[qr])) * (y(q[qr]) - y(q[qr - 1]))) qr--;
        q[++qr] = i - T + 1;
    }
    //for (int i = 1; i <= n; i++) cout << i << ' ' << dp[i] << '\n';
    cout << dp[n] << '\n';
}

int main() {
    while (cin >> n >> T) {
        solve();
    }
    return 0;
}
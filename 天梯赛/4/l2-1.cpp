#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e3 + 5;

int n, m, cap, p[N];
string s[N];
string stk;

void push(int x) {
    if (p[x] == -1) return;
    if ((int)(stk.size()) == cap) {
        auto it = stk.end();
        --it;
        cout << *it;
        stk.erase(it);
    }
    stk += s[x][p[x]--];
}

void solve() {
    cin >> n >> m >> cap;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        reverse(s[i].begin(), s[i].end());
        p[i] = m - 1;
    }
    int x;
    while (cin >> x && x != -1) {
        if (x != 0)push(x);
        else {
            if (stk.empty()) continue;
            auto it = stk.end();
            --it;
            cout << *it;
            stk.erase(it);
        }
    }
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
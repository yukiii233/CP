#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 2e5 + 5;

int n, Q;
multiset<int> s[N];
map<int, set<int>> mp;

void print(auto &s) {
    for (int x : s) cout << x << ' ';
    cout << '\n';
}

void solve() {
    cin >> n >> Q;
    for (int r = 1; r <= Q; r++) {
        int op, i, j;
        cin >> op;
        if (op == 1) {
            cin >> i >> j;
            s[j].insert(i);
            mp[i].insert(j);
        } else if (op == 2) {
            cin >> i;
            print(s[i]);
        } else {
            cin >> i;
            print(mp[i]);
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
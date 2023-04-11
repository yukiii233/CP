#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

int n, m;

map<vector<int>, int> mp;
vector<vector<int>> p[N];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        vector<int> v;
        for (int j = 1; j <= m; j++) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        mp[v]++;
    }
    for (auto x : mp) {
        p[x.second].push_back(x.first);
    }
    cout << mp.size() << '\n';
    for (int i = n; i; i--) if (!p[i].empty()) {
        sort(p[i].begin(), p[i].end(), [](vector<int> a, vector<int> b) {
            for (int i = 0; i < m; i++) if (a[i] != b[i]) return a[i] < b[i];
        });
        for (auto x : p[i]) {
            cout << i;
            for (auto q : x) cout << ' ' << q; 
            cout << '\n';
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